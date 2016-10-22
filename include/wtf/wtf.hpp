#pragma once

#define NOMINMAX 1

#include <Windows.h>
#include <windowsx.h>
#include <tchar.h>

#include <algorithm>
#include <stdexcept>
#include <string>
#include <cassert>
#include <typeinfo>
#include <memory>
#include <vector>
#include <map>
#include <functional>
#include <iterator>
#include <sstream>
#include <mutex>


namespace wtf{

  using tstring = std::basic_string<TCHAR>;
  using tstringstream = std::basic_stringstream<TCHAR>;

  enum class coord_frame{
    screen,
    client,
  };

  extern "C" HINSTANCE__ __ImageBase;
  inline static HINSTANCE instance_handle(){ return &__ImageBase; }


  template <typename, template <typename,typename> class ...> struct window;

  namespace policy{
    template <template <typename, typename> class> struct traits;

    template <template <typename, typename> class ...> struct type_list;

    template <template <typename, typename> class _HeadT, template <typename, typename> class ..._TailT>
    struct type_list<_HeadT, _TailT...> : type_list<_TailT...>{};

    template <> struct type_list<>{};
  }
  namespace _{
    template <typename, template <typename, typename> class ... > struct base_window;
  }
}


#include "exception.hpp"
#include "message_box.hpp"
#include "callback.hpp"
#include "point.hpp"
#include "color.hpp"
#include "rect.hpp"
#include "size.hpp"
#include "icon.hpp"
#include "cursor.hpp"
#include "brush.hpp"
#include "pen.hpp"
#include "region.hpp"
#include "font.hpp"

#include "detail/window_class_ex.hpp"
#include "detail/msg_names.hpp"
#include "detail/weak_enum.hpp"
#include "detail/device_context.hpp"
#include "detail/text_metrics.hpp"
#include "detail/paint_struct.hpp"
#include "detail/base_window.hpp"
#include "detail/SystemParameters.hpp"
#include "detail/message.hpp"




#include "messages/messages.hpp"
#include "messages/wm_activate.hpp"
#include "messages/wm_char.hpp"
#include "messages/wm_dblclick.hpp"
#include "messages/wm_geticon.hpp"
#include "messages/wm_keydown.hpp"
#include "messages/wm_keyup.hpp"
#include "messages/wm_killfocus.hpp"
#include "messages/wm_mouse_down.hpp"
#include "messages/wm_mouse_leave.hpp"
#include "messages/wm_mouse_move.hpp"
#include "messages/wm_mouse_up.hpp"
#include "messages/wm_mouse_wheel.hpp"
#include "messages/wm_move.hpp"
#include "messages/wm_moving.hpp"
#include "messages/wm_paint.hpp"
#include "messages/wm_setcursor.hpp"
#include "messages/wm_setfocus.hpp"
#include "messages/wm_showwindow.hpp"
#include "messages/wm_size.hpp"
#include "messages/wm_sizing.hpp"
#include "messages/wm_timer.hpp"



#include "policies/has_border.hpp"
#include "policies/has_caret.hpp"
#include "policies/has_click.hpp"
#include "policies/has_close.hpp"
#include "policies/has_create.hpp"
#include "policies/has_cursor.hpp"
#include "policies/has_dblclick.hpp"
#include "policies/has_focus.hpp"
#include "policies/has_font.hpp"
#include "policies/has_icon.hpp"
#include "policies/has_keyboard.hpp"
#include "policies/has_mouse_leave.hpp"
#include "policies/has_mouse_down.hpp"
#include "policies/has_mouse_up.hpp"
#include "policies/has_mouse_move.hpp"
#include "policies/has_mouse_wheel.hpp"
#include "policies/has_move.hpp"
#include "policies/has_moving.hpp"
#include "policies/has_orientation.hpp"
#include "policies/has_paint.hpp"
#include "policies/has_repeat_click.hpp"
#include "policies/has_show.hpp"
#include "policies/has_size.hpp"
#include "policies/has_sizing.hpp"
#include "policies/has_text.hpp"
#include "policies/has_timer.hpp"
#include "policies/has_titlebar.hpp"
#include "policies/has_zorder.hpp"
#include "policies/has_button_border.hpp"



#include "ui/window.hpp"
#include "ui/menu.hpp"
#include "ui/form.hpp"
#include "ui/label.hpp"
#include "ui/button.hpp"
#include "ui/scroll_bar.hpp"
#include "ui/panel.hpp"
#include "ui/progress_bar.hpp"
#include "ui/checkbox.hpp"
#include "ui/rivet.hpp"
#include "ui/listbox.hpp"
#include "ui/textbox.hpp"
#include "ui/toggle_button.hpp"
#include "ui/tab_container.hpp"
#include "ui/split_container.hpp"
#include "ui/tree.hpp"
