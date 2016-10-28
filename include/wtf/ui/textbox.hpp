#pragma once

namespace wtf{

  namespace policy{

    template <typename _ImplT, typename _SuperT>
    class isa_textbox : public _SuperT{

      
    public:

    protected:
      virtual void handle_msg(window_message& msg) override{}
      explicit isa_textbox(iwindow * pParent) : _SuperT(pParent){}

      virtual void on_wm_create() override{
        background_brush(brush::system_brush(system_colors::window));
        border_style(border_styles::lowered);
        text_vertical_alignment(text_vertical_alignments::top);
        text_horizontal_alignment(text_horizontal_alignments::left);
        caret_width(2);
        auto_draw_text(false);
        _SuperT::on_wm_create();
      };

      virtual void on_wm_paint(const device_context& dc, const paint_struct& ps) override{
        if (!_text.size()) return _SuperT::on_wm_paint(dc, ps);

        rect<coord_frame::client> client = ps.client();
        auto ClientWidth = client.right - client.left;

        //sanity checks
        if (_print_pos < 0) _print_pos = 0;
        if (_edit_pos < 0) _edit_pos = 0;
        if (_edit_pos > static_cast<int>(_text.size())) _edit_pos = static_cast<int>(_text.size());
        if (_print_pos >= _edit_pos && _edit_pos) _print_pos = _edit_pos - 1;


        int EndPrintPos = _edit_pos;
        point<coord_frame::client> CaretPos;

        for (;;){
          auto tmpExt = dc.get_text_extent(_text.c_str() + _print_pos, EndPrintPos - _print_pos);
          CaretPos.x = tmpExt.cx;
          CaretPos.y = tmpExt.cy;
          if (tmpExt.cx <= ClientWidth) break;
          _print_pos++;
        }


        for (;;){
          auto tmpEndPos = 1 + EndPrintPos;
          if (tmpEndPos >= _text.size()) break;
          auto tmpExt = dc.get_text_extent(_text.c_str() + _print_pos, tmpEndPos - _print_pos);
          if (tmpExt.cx > ClientWidth) break;
          EndPrintPos = tmpEndPos;
        }

        text(_text.substr(_print_pos, EndPrintPos - _print_pos));

        bool bCaretVisible = caret_visible();
        if (bCaretVisible) caret_visible(false);

        CaretPos.y = border_width();

        draw_text(dc, client);

        if (bCaretVisible){
          caret_visible(true);
          caret_position(CaretPos);
        }
        _SuperT::on_wm_paint(dc, ps);
      };


      virtual void on_wm_mouse_up(const mouse_msg_param& p) override{
        set_focus();
        _SuperT::on_wm_mouse_up(p);
      };


      virtual void on_wm_char(UINT character, keyboard_msg_param k) override{
        switch (character){
          case VK_BACK:
          {
            if (_edit_pos) _text.erase(--_edit_pos, 1); break;
          }
          default:
          {
            _text.insert(_edit_pos++, 1, static_cast<char>(character)); break;
          }
        }
        invalidate();
        _SuperT::on_wm_char(character, k);
      };

      virtual void on_wm_keydown(UINT key, keyboard_msg_param k) override{

        switch (key){
          case VK_LEFT:
          {
            _edit_pos--; break;
          }
          case VK_RIGHT:
          {
            _edit_pos++; break;
          }
          case VK_HOME:
          {
            _edit_pos = _print_pos = 0; break;
          }
          case VK_END:
          {
            _edit_pos = static_cast<int>(_text.size()); break;
          }
        }
        if (_edit_pos < 0) _edit_pos = 0;
        if (_edit_pos > static_cast<int>(_text.size())) _edit_pos = static_cast<int>(_text.size());
        invalidate();
        _SuperT::on_wm_keydown(key, k);

      };

      virtual const wtf::cursor& cursor_pointer() const override{ return cursor::global(cursor::style::ibeam); }

    private:

      text_metrics _text_metrics;
      // _edit_pos tracks the index into _text for the edit cursor 
      int _edit_pos = 0;
      // _print_pos helps ensure the cursor is always visible e.g. text length > window length
      int _print_pos = 0;
    };
  }

  struct textbox : window_impl<textbox, policy::isa_textbox>{
    explicit textbox(iwindow * pParent) : window_impl(pParent){}
  };

}
