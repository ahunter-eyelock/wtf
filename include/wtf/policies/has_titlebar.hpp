#pragma once

namespace wtf {
  namespace policy {

    /** has_titlebar
    * Adds titlebar text features to windows
    */
    template<typename _SuperT, typename _ImplT>
    struct has_titlebar : _SuperT {

      const tstring &titlebar() const {
        return _titlebar;
      }

      void titlebar(LPCTSTR newval) {
        wtf::exception::throw_lasterr_if(::SetWindowText(*this, newval), [](BOOL b) { return !b; });
        _titlebar = newval;
      }

    protected:
      explicit has_titlebar(window<void,void> * pParent) : _SuperT(pParent){}
    private:
      tstring _titlebar = _T("");
    };

  }
}
