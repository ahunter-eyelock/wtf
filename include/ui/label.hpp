#pragma once
namespace wtf{

    struct label : window<label, policy::has_cursor, policy::has_paint, policy::has_size,
      policy::has_show, policy::has_text, policy::has_border, policy::has_click>
    {
      label() = delete;
      label(const label&) = delete;
      label(label&&) = delete;
      label &operator=(const label &) = delete;
      label &operator=(label&&) = delete;
      virtual ~label() = default;
      explicit label(HWND hParent) : window(hParent, true)
      {
        this->border_style(border_styles::none);
      }
    protected:

      virtual void PaintEvent(const device_context& oDC, const paint_struct& oPS){
        auto client = oPS.client();
        client.top += border_width();
        client.left += border_width();
        client.bottom -= border_width();
        client.right -= border_width();
        this->DrawText(oDC, client);
      }

    };

}