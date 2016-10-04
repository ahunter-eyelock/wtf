#pragma once
namespace wtf{

    struct listbox : wtf::window<listbox, policy::has_border, policy::has_click,
      policy::has_paint, policy::has_size, policy::has_timer, policy::has_mouse>
    {
      static const int scroll_width = 15;
      static const int left_margin = 2;
      static const int right_margin = 2;
      static const int top_margin = 2;
      static const int bottom_margin = 2;

      enum class selection_modes{
        single,
        multiple,
      };

      selection_modes selection_mode() const{ return _selection_mode; }
      void selection_mode(selection_modes newval){ _selection_mode = newval; }

      void add_item(const tstring& newval){
        _Items.push_back(newval);
      }
      listbox(const listbox&) = delete;
      listbox(listbox&&) = delete;
      listbox &operator=(const listbox &) = delete;
      listbox &operator=(listbox&&) = delete;

      explicit listbox(HWND hParent) : 
        window(hParent), 
        _TopIndex(0), 
        _SelectedItems(1, 0),
        _vscroll(*this),
        _selection_mode(selection_modes::single)
      {
        _vscroll.orientation(scroll_bar::orientations::vertical);
        background_brush(brush::system_brush(system_colors::window));
        border_edge(border_edges::thin_raised);
        ResizedEvent.connect([this](wm_size_flags, int width, int height){
          _vscroll.move(width - scroll_width - right_margin, top_margin, scroll_width, height - top_margin - bottom_margin);
        });
        PaintEvent.connect([this](const device_context& oDC, const paint_struct& ){
          auto flags = device_context::draw_text_flags::left;
          if (!_Items.size()) return;
          auto client = rect::get_client_rect(*this);
          auto oTextSize = oDC.get_text_extent(_Items[0]);
          _ItemRects.clear();
          int listWidth = client.right - right_margin - scroll_width - left_margin;
          for (int i = top_margin; i < client.bottom; i += oTextSize.cy){
            _ItemRects.push_back(rect(left_margin, i, listWidth, std::min(i + oTextSize.cy, client.bottom - bottom_margin)));
          }

          for (size_t i = 0; i < _ItemRects.size() && (_TopIndex + i) < _Items.size(); ++i){
            oDC.background_mix_mode(device_context::background_mix_modes::opaque);
            for (size_t x = 0; x < _SelectedItems.size(); x++){
              if (_SelectedItems[x] == (_TopIndex + static_cast<int>(i))){
                oDC.fill(_ItemRects[i], brush::system_brush(system_colors::highlight));
                oDC.background_mix_mode(device_context::background_mix_modes::transparent);
                break;
              }
            }
            oDC.draw_text(_Items[i + _TopIndex], _ItemRects[i], flags);
          }
        });
        _vscroll.increment_button.ClickEvent.connect([this](const point&){
          if ((_TopIndex + _ItemRects.size()) < _Items.size()) _TopIndex++;
          refresh(true);
        });
        _vscroll.decrement_button.ClickEvent.connect([this](const point&){
          if (!_TopIndex) return;
          --_TopIndex;
          refresh(true);
        });
        ClickEvent.connect([this](const point& p){
          if (selection_modes::single == _selection_mode){
            _SelectedItems.clear();
          }
          for (size_t i = 0; i < _ItemRects.size() && (_TopIndex + i) < _Items.size(); ++i){
            if (!_ItemRects[i].is_in(p)) continue;
            _SelectedItems.push_back(_TopIndex + static_cast<int>(i));
          }
          refresh(true);
        });
        TimerEvent.connect([this](UINT_PTR iTimer){
          if (iTimer != _MouseDownTimer) return;
          kill_timer(_MouseDownTimer);
          _MouseDownTimer = set_timer(10);
          if (_IncrementHeldDown){
            _vscroll.increment_button.ClickEvent(_MouseDownAt);
          } else{
            _vscroll.decrement_button.ClickEvent(_MouseDownAt);
          }
        });
        _vscroll.increment_button.MouseLButtonDownEvent.connect([this](event_vkeys, const point& p){
          _MouseDownAt = p;
          _IncrementHeldDown = true;
          _MouseDownTimer = set_timer(500);
        });
        _vscroll.increment_button.MouseLButtonUpEvent.connect([this](event_vkeys, const point& ){
          kill_timer(_MouseDownTimer);
        });
        _vscroll.decrement_button.MouseLButtonDownEvent.connect([this](event_vkeys, const point& p){
          _MouseDownAt = p;
          _IncrementHeldDown = false;
          _MouseDownTimer = set_timer(500);
        });
        _vscroll.decrement_button.MouseLButtonUpEvent.connect([this](event_vkeys, const point& ){
          kill_timer(_MouseDownTimer);
        });
        MouseWheelEvent.connect([this](event_vkeys, short delta, const point& p){
          if (delta < 0){
            _vscroll.increment_button.ClickEvent(p);
          } else{
            _vscroll.decrement_button.ClickEvent(p);
          }
        });
      }

    protected:
      UINT_PTR _MouseDownTimer;
      bool _IncrementHeldDown;
      point _MouseDownAt;
      int _TopIndex;
      std::vector<tstring> _Items;
      std::vector<rect> _ItemRects;
      std::vector<int> _SelectedItems;
      scroll_bar _vscroll;
      selection_modes _selection_mode;
    };

}
