/** @file
@copyright David Mott (c) 2016. Distributed under the Boost Software License Version 1.0. See LICENSE.md or http://boost.org/LICENSE_1_0.txt for details.
*/
#pragma once

#if 0
namespace wtf{
  namespace policy{

    class splitter : public window_impl<splitter, policy::has_cursor, policy::wm_mouse_move, policy::isa_panel, policy::has_orientation>{
      using _super_t = window_impl<splitter, policy::has_cursor, policy::wm_mouse_move, policy::isa_panel, policy::has_orientation>;

    public:

      splitter(window * pParent) noexcept : _super_t(pParent){}

      callback<void(const point<coord_frame::client>&)> OnMoved;

    protected:

      virtual void size_bar_moved(const point<coord_frame::client>& p){ OnMoved(p); }
      TODO("Fix me");
      /*

      void on_wm_mouse_move(const mouse_msg_param<coord_frame::client>& m) override{
        if (m.key_state & mouse_key_states::left) size_bar_moved(m.position);        
        _super_t::on_wm_mouse_move(m);
      };

      void on_wm_mouse_down(const mouse_msg_param<coord_frame::client>& m) override{
        if (mouse_buttons::left == m.button) SetCapture(*this);        
        _super_t::on_wm_mouse_down(m);
      };

      void on_wm_mouse_up(const mouse_msg_param<coord_frame::client>& m) override{
        ReleaseCapture();
        _super_t::on_wm_mouse_up(m);
      };
      */

      const wtf::cursor &cursor_pointer() const override{
        if (orientations::horizontal == _super_t::orientation()){
          return cursor::global(cursor::style::size_ns);
        } else{
          return cursor::global(cursor::style::size_we);
        }
      }

    };

    template <typename _super_t>
    struct isa_split_container : _super_t{


      panel& first(){ return _first; }
      const panel& first() const{ return _first; }

      panel& second(){ return _second; }
      const panel& second() const{ return _second; }

      int splitter_width() const{ return _splitter_width; }
      void splitter_width(int newval){
        _splitter_width = newval;
        _super_t::invalidate();
      }

      void set_split_absolute(int pixels){
        _splitter_pos = pixels;
        auto oSize = rect<coord_frame::client>::get(*this);
        _super_t::move(oSize.left, oSize.top, oSize.right, oSize.bottom);
      }

      void set_split_relative(int percent){
        auto oSize = rect<coord_frame::client>::get(*this);
        if (orientations::horizontal == _super_t::orientation()){
          if (oSize.bottom) _splitter_pos = (percent * oSize.bottom / 100);
        } else{
          if (oSize.right) _splitter_pos = (percent * oSize.right / 100);
        }
        _super_t::move(oSize.left, oSize.top, oSize.right, oSize.bottom);
      }

      TODO("Fix me");
      /*
      void orientation(orientations newval) noexcept override{
        _splitter.orientation(newval);
        _super_t::orientation(newval);
      }
      */

    protected:

      explicit isa_split_container(window * pParent) : _super_t(pParent), _first(this), _second(this), _splitter(this){}
      
      TODO("Fix me");
      /*
      void on_wm_size(const point<coord_frame::client>& p) override{
        if (orientations::horizontal == _super_t::orientation()) {
          if (_splitter_pos < 10) _splitter_pos = 10;
          if (_splitter_pos > p.y - 10) _splitter_pos = p.y - 10;
          _first.move(0, 0, p.x, _splitter_pos);
          _splitter.move(0, _splitter_pos, p.x, _splitter_width);
          _second.move(0, _splitter_pos + _splitter_width, p.x, p.y - _splitter_pos - _splitter_width);
        } else{
          if (_splitter_pos < 10) _splitter_pos = 10;
          if (_splitter_pos > p.x - 10) _splitter_pos = p.x - 10;
          _first.move(0, 0, _splitter_pos, p.y);
          _splitter.move(_splitter_pos, 0, _splitter_width, p.y);
          _second.move(_splitter_pos + _splitter_width, 0, p.x - _splitter_pos - _splitter_width, p.y);
        }
        _super_t::on_wm_size(p);
      };
      */

      void size_bar_moved(const point<coord_frame::client>& p){
        if (orientations::horizontal == _super_t::orientation()) {
          _splitter_pos = _splitter.top() + p.y;
        } else{
          _splitter_pos = _splitter.left() + p.x;
        }
        auto oSize = rect<coord_frame::client>::get(*this);
        on_wm_size(oSize.dimensions());
      }


      class size_bar : public splitter{
      public:
        size_bar(isa_split_container * pParent)  noexcept : splitter(pParent), _parent(pParent) {}

        void size_bar_moved(const point<coord_frame::client>& pos) override{
          _parent->size_bar_moved(pos);
          splitter::size_bar_moved(pos);
        }

        isa_split_container * _parent;

      }_splitter;

    private:
      int _splitter_width = 5;
      int _splitter_pos = 0;
      panel _first, _second;

    };
  }

  namespace _{

    template <> struct policy_traits<policy::isa_split_container>{
      using requires = policy_list< policy::isa_panel, policy::has_orientation>;
    };

  }

  struct split_container : window_impl<split_container, policy::isa_split_container>{
    explicit split_container(window * pParent) noexcept : window_impl(pParent){}
  };


}
#endif