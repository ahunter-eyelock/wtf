#pragma once
namespace wtf{

    struct label : window<label, policy::has_cursor, policy::has_paint, policy::has_size,
      policy::has_show, policy::has_text, policy::has_border, policy::has_click, policy::has_zorder, 
      policy::has_mouse_down, policy::has_mouse_move, policy::has_mouse_up
    >
    {

      explicit label(HWND hParent) : window(hParent, true)
      {
        this->border_style(border_styles::none);
      }


    };

}
