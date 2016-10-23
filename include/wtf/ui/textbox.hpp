#pragma once

namespace wtf{

    struct textbox : wtf::window<textbox, policy::has_focus, policy::has_cursor, policy::has_caret, 
      policy::has_size, policy::has_border, policy::has_click, policy::has_text, policy::has_background,
      messages::wm_paint,messages::wm_mouse_down, messages::wm_create, messages::wm_char, messages::wm_keydown, 
      messages::wm_erasebkgnd, messages::wm_nccalcsize, messages::wm_ncpaint, messages::wm_mouse_up, 
      messages::wm_mouse_down, messages::wm_setfocus, messages::wm_killfocus, messages::wm_setcursor>
    {

      using mouse_msg_param = messages::mouse_msg_param;

      explicit textbox(window<void,void> * pParent) : window(pParent){}

      virtual LRESULT on_wm_create(bool& bHandled) override{
        background_brush(brush::system_brush(system_colors::window));
        border_style(border_styles::lowered);
        text_vertical_alignment(text_vertical_alignments::top);
        text_horizontal_alignment(text_horizontal_alignments::left);
        caret_width(2);
        auto_draw_text(false);
        return window::on_wm_create(bHandled);
      };

      virtual void on_wm_click(const mouse_msg_param& m) override{ return window::on_wm_click(m); }

      virtual LRESULT on_wm_paint(const device_context& dc, const paint_struct& ps, bool& bHandled) override{
        if (!_text.size()) return window::on_wm_paint(dc, ps, bHandled);

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
          CaretPos.y = _text_metrics.tmHeight;
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
        return window::on_wm_paint(dc, ps, bHandled);
      };

      virtual LRESULT on_wm_mouse_down(const mouse_msg_param& p, bool& bHandled) override{
        set_focus();
        return window::on_wm_mouse_down(p, bHandled);
      };

      virtual LRESULT on_wm_char(UINT character, messages::keyboard_msg_param k, bool& bHandled) override{
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
        //         refresh();
        return window::on_wm_char(character, k, bHandled);
      };

      virtual LRESULT on_wm_keydown(UINT key, messages::keyboard_msg_param k, bool& bHandled) override{

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
        return window::on_wm_keydown(key, k, bHandled);

      };

      virtual const wtf::cursor& cursor_pointer() const override{ return cursor::global(cursor::style::ibeam); }

      virtual const tstring &text() const{ return _text; }
      virtual void text(const tstring &newval){ 
        _edit_pos = 0; 
        _text = newval; 
        invalidate();
      }



    private:

      text_metrics _text_metrics;
      // _edit_pos tracks the index into _text for the edit cursor 
      int _edit_pos = 0;
      // _print_pos helps ensure the cursor is always visible e.g. text length > window length
      int _print_pos = 0;
      tstring _text = _T("");
      bool _word_wrap = false;
      std::map<TCHAR, uint8_t> _CharWidths;
    };

}
