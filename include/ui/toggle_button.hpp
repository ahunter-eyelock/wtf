#pragma once

namespace wtf{

    struct toggle_button : wtf::window<toggle_button, policy::has_size, policy::has_border,
      policy::has_click, policy::has_text, policy::has_font, policy::has_paint, policy::has_mouse>
    {
      toggle_button() = delete;
      toggle_button(const toggle_button&) = delete;
      toggle_button(toggle_button&&) = delete;
      toggle_button &operator=(const toggle_button &) = delete;
      toggle_button &operator=(toggle_button&&) = delete;
      virtual ~toggle_button() = default;
      explicit toggle_button(HWND hParent) : window(hParent, true), _button_state(button_states::up){
        border_style(border_styles::raised);
      }

      enum class button_states{
        up,
        down,
      };

      button_states button_state() const{ return _button_state; }
      void button_state(button_states newval) { 
        if (newval == _button_state) return;
        _button_state=newval;
        border_style((button_states::down == _button_state ? border_styles::lowered : border_styles::raised));
        refresh();
      }

    private:

      virtual void MouseLButtonUpEvent(event_vkeys, const point::client_coords&) override{
        button_state(button_states::down == _button_state ? button_states::up : button_states::down);
      }

      virtual void PaintEvent(const device_context& dc, const paint_struct& ps){
        rect::client_coord client = ps.client();
        client.top += border_width();
        client.left += border_width();
        client.bottom -= border_width();
        client.right -= border_width();
        if (button_states::down == _button_state){
          client.top++;
          client.left++;
        }
        DrawText(dc, client);
      }


      button_states _button_state;
    };

}