#pragma once

namespace wtf {

    struct menu : std::shared_ptr<HMENU__> {
      menu() : shared_ptr(CreateMenu(), ::DestroyMenu){}
    private:
      
    };


  }