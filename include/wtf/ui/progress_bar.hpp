#pragma once

namespace wtf{

  struct progress_bar : wtf::window < progress_bar, policy::has_border, policy::has_size, policy::has_move,
    policy::has_text, policy::has_font, messages::wm_paint, policy::has_orientation, messages::wm_create, 
    policy::has_background, messages::wm_erasebkgnd, messages::wm_nccalcsize, messages::wm_ncpaint >
  {

    explicit progress_bar(window<void,void> * hParent) : window(hParent){}

    virtual LRESULT on_wm_create(bool& bHandled) override{
      border_style(border_styles::lowered);
      auto_draw_text(false);
      return window::on_wm_create(bHandled);
    };

    int min() const{ return _min; }
    void min(int newval){ 
      _min = newval; 
      invalidate();
    }

    int max() const{ return _max; }
    void max(int newval){ 
      _max = newval; 
      invalidate();
    }

    int value() const{ return _value; }
    void value(int newval){ 
      _value = newval; 
      invalidate();
    }

    rgb fill_color() const{ return _fill_color; }
    void fill_color(rgb newval){
      _fill_color = newval; 
      invalidate();
    }

    enum class text_modes{
      none,
      value,
      percentage,
    };

    text_modes text_mode() const{ return _text_mode; }
    void text_mode(text_modes newval){ 
      _text_mode = newval; 
      invalidate();
    }
  protected:

    int _min = 0;
    int _max = 100;
    int _value = 0;
    rgb _fill_color = system_rgb<system_colors::highlight>();
    text_modes _text_mode = text_modes::percentage;

    virtual LRESULT on_wm_paint(const device_context& dc, const paint_struct& ps, bool& bHandled) override {
      auto oBrush = brush::solid_brush(_fill_color);
      rect<coord_frame::client> oFillArea = ps.client();
      auto iExtent = _max - _min;
      if (orientations::horizontal == orientation()){
        oFillArea.right = (oFillArea.right * _value) / iExtent;
      } else{
        oFillArea.top = (oFillArea.top * _value) / iExtent;
      }
      dc.fill(oFillArea, oBrush);
      if (text_modes::none == _text_mode) return window::on_wm_paint(dc, ps, bHandled);
      //poor mans utf8 conversion...get with the program mingw
      tstring sDisplayText;
      std::string sTemp;
      if (text_modes::percentage == _text_mode){
        int iTemp = 100 - ((_value * 100) / (_max - _min));
        sTemp = std::to_string(iTemp);
        sTemp += "%";
      } else{
        sTemp = std::to_string(_value);
      }
      std::copy(sTemp.begin(), sTemp.end(), std::back_inserter(sDisplayText));
      auto oTextSize = dc.get_text_extent(sDisplayText);
      text(sDisplayText);
      oFillArea.right = std::max(oTextSize.cx, oFillArea.right);
      text_vertical_alignment(text_vertical_alignments::center);
      text_horizontal_alignment(text_horizontal_alignments::center);
      return window::on_wm_paint(dc, ps, bHandled);
    }


  };

}
