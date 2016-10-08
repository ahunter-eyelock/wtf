#pragma once
namespace wtf{
  struct checkbox : window<checkbox, policy::has_paint, policy::has_click, policy::has_size, policy::has_text>{
    checkbox(HWND parent) : window(parent), _check(*this){
      _check.border_style(panel::border_styles::raised);
      auto_draw_text(false);
      check_location(check_locations::left);
    }

    enum class check_locations{
      left,
      right,
    };

    check_locations check_location() const{ return _check_location; }
    void check_location(check_locations newval){ 
      _check_location = newval; 
      if (check_locations::left == _check_location){
        text_horizontal_alignment(text_horizontal_alignments::left);
      } else{
        text_horizontal_alignment(text_horizontal_alignments::right);
      }
    }

    callback<void(bool)> ValueChanged;

  private:

    static const int checkbox_size = 15;

    virtual void ClickEvent(const point::client_coords&) override{
      _check.value(!_check.value());
    }

    virtual void PaintEvent(const device_context& dc, const paint_struct& ps) override{
      auto client = ps.client();
      auto TextSize = prefered_text_size();
      if (check_locations::left == _check_location){
        _check.move(0, (client.bottom - checkbox_size) / 2, checkbox_size, checkbox_size);
        draw_text(dc, rect::client_coord(checkbox_size + 3, 0, client.right - checkbox_size - 3, client.bottom));
      } else{
        _check.move(client.right- checkbox_size, (client.bottom - checkbox_size) / 2, checkbox_size, checkbox_size);
        draw_text(dc, rect::client_coord(0, 0, client.right - checkbox_size - 3, client.bottom));
      }
    }

    struct _check : panel{
      _check(checkbox& parent) 
        : panel(parent), 
        _parent(parent)
      {}

      virtual void ClickEvent(const point::client_coords&) override{
        value(!_value);
      }

      virtual void PaintEvent(const device_context& dc, const paint_struct& ps) override{
        auto client = ps.client();
        client.top++;
        client.left++;
        client.bottom--;
        client.right--;
        dc.fill(client, brush::solid_brush(rgb(255, 255, 255)));
        if (_value){
          auto black = pen::create(pen::style::solid, 2, rgb(0, 0, 0));
          dc.line(black, client.left, client.top, client.right, client.bottom);
          dc.line(black, client.right, client.top, client.left, client.bottom);
        }
      }


      bool value() const{ return _value; }
      void value(bool newval){
        _value = newval;
        border_style(newval ? border_styles::lowered : border_styles::raised);
        refresh();
        _parent.ValueChanged(newval);
      }

      bool _value = false;
      checkbox& _parent;
    }_check;
    check_locations _check_location = check_locations::left;
  };
}