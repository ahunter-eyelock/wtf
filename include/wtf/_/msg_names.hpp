﻿/** @file
@copyright David Mott (c) 2016. Distributed under the Boost Software License Version 1.0. See LICENSE.md or http://boost.org/LICENSE_1_0.txt for details.
*/
#pragma once

namespace wtf {
  namespace _ {
    static const tstring msg_name(UINT msg) {
      static std::map <UINT, tstring> names = {
      #if defined(WM_MOUSEHWHEEL)
        {  WM_MOUSEHWHEEL, _T("WM_MOUSEHWHEEL") },
      #endif
      #if defined(WM_POINTERDEVICECHANGE)
        {  WM_POINTERDEVICECHANGE, _T("WM_POINTERDEVICECHANGE") },
        {  WM_POINTERDEVICEINRANGE, _T("WM_POINTERDEVICEINRANGE") },
        {  WM_POINTERDEVICEOUTOFRANGE, _T("WM_POINTERDEVICEOUTOFRANGE") },
        {  WM_TOUCH, _T("WM_TOUCH") },
        {  WM_NCPOINTERUPDATE, _T("WM_NCPOINTERUPDATE") },
        {  WM_NCPOINTERDOWN, _T("WM_NCPOINTERDOWN") },
        {  WM_NCPOINTERUP, _T("WM_NCPOINTERUP") },
        {  WM_POINTERUPDATE, _T("WM_POINTERUPDATE") },
        {  WM_POINTERDOWN, _T("WM_POINTERDOWN") },
        {  WM_POINTERUP, _T("WM_POINTERUP") },
        {  WM_POINTERENTER, _T("WM_POINTERENTER") },
        {  WM_POINTERLEAVE, _T("WM_POINTERLEAVE") },
        {  WM_POINTERACTIVATE, _T("WM_POINTERACTIVATE") },
        {  WM_POINTERCAPTURECHANGED, _T("WM_POINTERCAPTURECHANGED") },
        {  WM_TOUCHHITTESTING, _T("WM_TOUCHHITTESTING") },
        {  WM_POINTERWHEEL, _T("WM_POINTERWHEEL") },
        {  WM_POINTERHWHEEL, _T("WM_POINTERHWHEEL") },
      #if defined(WM_POINTERROUTEDTO)
        {  WM_POINTERROUTEDTO, _T("WM_POINTERROUTEDTO") },
        {  WM_POINTERROUTEDAWAY, _T("WM_POINTERROUTEDAWAY") },
        {  WM_POINTERROUTEDRELEASED, _T("WM_POINTERROUTEDRELEASED") },
      #endif
      #endif
      #if defined(WM_DPICHANGED)
        {  WM_DPICHANGED, _T("WM_DPICHANGED") },
      #endif
      #if defined(WM_DWMCOMPOSITIONCHANGED)
        {  WM_DWMCOMPOSITIONCHANGED, _T("WM_DWMCOMPOSITIONCHANGED") },
        {  WM_DWMNCRENDERINGCHANGED, _T("WM_DWMNCRENDERINGCHANGED") },
        {  WM_DWMCOLORIZATIONCOLORCHANGED, _T("WM_DWMCOLORIZATIONCOLORCHANGED") },
        {  WM_DWMWINDOWMAXIMIZEDCHANGE, _T("WM_DWMWINDOWMAXIMIZEDCHANGE") },
#if defined(WM_DWMSENDICONICTHUMBNAIL)
        {  WM_DWMSENDICONICTHUMBNAIL, _T("WM_DWMSENDICONICTHUMBNAIL") },
#endif
#if defined(WM_DWMSENDICONICLIVEPREVIEWBITMAP)
        {  WM_DWMSENDICONICLIVEPREVIEWBITMAP, _T("WM_DWMSENDICONICLIVEPREVIEWBITMAP") },
#endif
        {  WM_GETTITLEBARINFOEX, _T("WM_GETTITLEBARINFOEX") },
      #endif
      #if defined(WM_GESTURE)
        {  WM_GESTURE,  _T("WM_GESTURE") },
        {  WM_GESTURENOTIFY,  _T("WM_GESTURENOTIFY") },
      #endif
      {  WM_NULL,  _T("WM_NULL") },
        { WM_CREATE,  _T("WM_CREATE") },
        { WM_DESTROY,  _T("WM_DESTROY") },
        { WM_MOVE,  _T("WM_MOVE") },
        { WM_SIZE,  _T("WM_SIZE") },
        { WM_ACTIVATE,  _T("WM_ACTIVATE") },
        { WM_SETFOCUS,  _T("WM_SETFOCUS") },
        { WM_KILLFOCUS,  _T("WM_KILLFOCUS") },
        { WM_ENABLE,  _T("WM_ENABLE") },
        { WM_SETREDRAW,  _T("WM_SETREDRAW") },
        { WM_SETTEXT,  _T("WM_SETTEXT") },
        { WM_GETTEXT,  _T("WM_GETTEXT") },
        { WM_GETTEXTLENGTH,  _T("WM_GETTEXTLENGTH") },
        { WM_PAINT,  _T("WM_PAINT") },
        { WM_CLOSE,  _T("WM_CLOSE") },
        { WM_QUERYENDSESSION,  _T("WM_QUERYENDSESSION") },
        { WM_QUERYOPEN,  _T("WM_QUERYOPEN") },
        { WM_ENDSESSION,  _T("WM_ENDSESSION") },
        { WM_QUIT,  _T("WM_QUIT") },
        { WM_ERASEBKGND,  _T("WM_ERASEBKGND") },
        { WM_SYSCOLORCHANGE,  _T("WM_SYSCOLORCHANGE") },
        { WM_SHOWWINDOW,  _T("WM_SHOWWINDOW") },
        { WM_WININICHANGE,  _T("WM_WININICHANGE") },
        { WM_SETTINGCHANGE,  _T("WM_SETTINGCHANGE") },
        { WM_DEVMODECHANGE,  _T("WM_DEVMODECHANGE") },
        { WM_ACTIVATEAPP,  _T("WM_ACTIVATEAPP") },
        { WM_FONTCHANGE,  _T("WM_FONTCHANGE") },
        { WM_TIMECHANGE,  _T("WM_TIMECHANGE") },
        { WM_CANCELMODE,  _T("WM_CANCELMODE") },
        { WM_SETCURSOR,  _T("WM_SETCURSOR") },
        { WM_MOUSEACTIVATE,  _T("WM_MOUSEACTIVATE") },
        { WM_CHILDACTIVATE,  _T("WM_CHILDACTIVATE") },
        { WM_QUEUESYNC,  _T("WM_QUEUESYNC") },
        { WM_GETMINMAXINFO,  _T("WM_GETMINMAXINFO") },
        { WM_PAINTICON,  _T("WM_PAINTICON") },
        { WM_ICONERASEBKGND,  _T("WM_ICONERASEBKGND") },
        { WM_NEXTDLGCTL,  _T("WM_NEXTDLGCTL") },
        { WM_SPOOLERSTATUS,  _T("WM_SPOOLERSTATUS") },
        { WM_DRAWITEM,  _T("WM_DRAWITEM") },
        { WM_MEASUREITEM,  _T("WM_MEASUREITEM") },
        { WM_DELETEITEM,  _T("WM_DELETEITEM") },
        { WM_VKEYTOITEM,  _T("WM_VKEYTOITEM") },
        { WM_CHARTOITEM,  _T("WM_CHARTOITEM") },
        { WM_SETFONT,  _T("WM_SETFONT") },
        { WM_GETFONT,  _T("WM_GETFONT") },
        { WM_SETHOTKEY,  _T("WM_SETHOTKEY") },
        { WM_GETHOTKEY,  _T("WM_GETHOTKEY") },
        { WM_QUERYDRAGICON,  _T("WM_QUERYDRAGICON") },
        { WM_COMPAREITEM,  _T("WM_COMPAREITEM") },
        { WM_GETOBJECT,  _T("WM_GETOBJECT") },
        { WM_COMPACTING,  _T("WM_COMPACTING") },
        { WM_COMMNOTIFY,  _T("WM_COMMNOTIFY") },
        { WM_WINDOWPOSCHANGING,  _T("WM_WINDOWPOSCHANGING") },
        { WM_WINDOWPOSCHANGED,  _T("WM_WINDOWPOSCHANGED") },
        { WM_POWER,  _T("WM_POWER") },
        { WM_COPYDATA,  _T("WM_COPYDATA") },
        { WM_CANCELJOURNAL,  _T("WM_CANCELJOURNAL") },
        { WM_NOTIFY,  _T("WM_NOTIFY") },
        { WM_INPUTLANGCHANGEREQUEST,  _T("WM_INPUTLANGCHANGEREQUEST") },
        { WM_INPUTLANGCHANGE,  _T("WM_INPUTLANGCHANGE") },
        { WM_TCARD,  _T("WM_TCARD") },
        { WM_HELP,  _T("WM_HELP") },
        { WM_USERCHANGED,  _T("WM_USERCHANGED") },
        { WM_NOTIFYFORMAT,  _T("WM_NOTIFYFORMAT") },
        { WM_CONTEXTMENU,  _T("WM_CONTEXTMENU") },
        { WM_STYLECHANGING,  _T("WM_STYLECHANGING") },
        { WM_STYLECHANGED,  _T("WM_STYLECHANGED") },
        { WM_DISPLAYCHANGE,  _T("WM_DISPLAYCHANGE") },
        { WM_GETICON,  _T("WM_GETICON") },
        { WM_SETICON,  _T("WM_SETICON") },
        { WM_NCCREATE,  _T("WM_NCCREATE") },
        { WM_NCDESTROY,  _T("WM_NCDESTROY") },
        { WM_NCCALCSIZE,  _T("WM_NCCALCSIZE") },
        { WM_NCHITTEST,  _T("WM_NCHITTEST") },
        { WM_NCPAINT,  _T("WM_NCPAINT") },
        { WM_NCACTIVATE,  _T("WM_NCACTIVATE") },
        { WM_GETDLGCODE,  _T("WM_GETDLGCODE") },
        { WM_SYNCPAINT,  _T("WM_SYNCPAINT") },
        { WM_NCMOUSEMOVE,  _T("WM_NCMOUSEMOVE") },
        { WM_NCLBUTTONDOWN,  _T("WM_NCLBUTTONDOWN") },
        { WM_NCLBUTTONUP,  _T("WM_NCLBUTTONUP") },
        { WM_NCLBUTTONDBLCLK,  _T("WM_NCLBUTTONDBLCLK") },
        { WM_NCRBUTTONDOWN,  _T("WM_NCRBUTTONDOWN") },
        { WM_NCRBUTTONUP,  _T("WM_NCRBUTTONUP") },
        { WM_NCRBUTTONDBLCLK,  _T("WM_NCRBUTTONDBLCLK") },
        { WM_NCMBUTTONDOWN,  _T("WM_NCMBUTTONDOWN") },
        { WM_NCMBUTTONUP,  _T("WM_NCMBUTTONUP") },
        { WM_NCMBUTTONDBLCLK,  _T("WM_NCMBUTTONDBLCLK") },
        { WM_NCXBUTTONDOWN,  _T("WM_NCXBUTTONDOWN") },
        { WM_NCXBUTTONUP,  _T("WM_NCXBUTTONUP") },
        { WM_NCXBUTTONDBLCLK,  _T("WM_NCXBUTTONDBLCLK") },
        { WM_INPUT_DEVICE_CHANGE,  _T("WM_INPUT_DEVICE_CHANGE") },
        { WM_INPUT,  _T("WM_INPUT") },
        { WM_KEYDOWN,  _T("WM_KEYDOWN") },
        { WM_KEYUP,  _T("WM_KEYUP") },
        { WM_CHAR,  _T("WM_CHAR") },
        { WM_DEADCHAR,  _T("WM_DEADCHAR") },
        { WM_SYSKEYDOWN,  _T("WM_SYSKEYDOWN") },
        { WM_SYSKEYUP,  _T("WM_SYSKEYUP") },
        { WM_SYSCHAR,  _T("WM_SYSCHAR") },
        { WM_SYSDEADCHAR,  _T("WM_SYSDEADCHAR") },
        { WM_UNICHAR,  _T("WM_UNICHAR") },
        { WM_KEYLAST,  _T("WM_KEYLAST") },
        { WM_KEYLAST,  _T("WM_KEYLAST") },
        { WM_IME_STARTCOMPOSITION,  _T("WM_IME_STARTCOMPOSITION") },
        { WM_IME_ENDCOMPOSITION,  _T("WM_IME_ENDCOMPOSITION") },
        { WM_IME_COMPOSITION,  _T("WM_IME_COMPOSITION") },
        { WM_IME_KEYLAST,  _T("WM_IME_KEYLAST") },
        { WM_INITDIALOG,  _T("WM_INITDIALOG") },
        { WM_COMMAND,  _T("WM_COMMAND") },
        { WM_SYSCOMMAND,  _T("WM_SYSCOMMAND") },
        { WM_TIMER,  _T("WM_TIMER") },
        { WM_HSCROLL,  _T("WM_HSCROLL") },
        { WM_VSCROLL,  _T("WM_VSCROLL") },
        { WM_INITMENU,  _T("WM_INITMENU") },
        { WM_INITMENUPOPUP,  _T("WM_INITMENUPOPUP") },
        { WM_MENUSELECT,  _T("WM_MENUSELECT") },
        { WM_MENUCHAR,  _T("WM_MENUCHAR") },
        { WM_ENTERIDLE,  _T("WM_ENTERIDLE") },
        { WM_MENURBUTTONUP,  _T("WM_MENURBUTTONUP") },
        { WM_MENUDRAG,  _T("WM_MENUDRAG") },
        { WM_MENUGETOBJECT,  _T("WM_MENUGETOBJECT") },
        { WM_UNINITMENUPOPUP,  _T("WM_UNINITMENUPOPUP") },
        { WM_MENUCOMMAND,  _T("WM_MENUCOMMAND") },
        { WM_CHANGEUISTATE,  _T("WM_CHANGEUISTATE") },
        { WM_UPDATEUISTATE,  _T("WM_UPDATEUISTATE") },
        { WM_QUERYUISTATE,  _T("WM_QUERYUISTATE") },
        { WM_CTLCOLORMSGBOX,  _T("WM_CTLCOLORMSGBOX") },
        { WM_CTLCOLOREDIT,  _T("WM_CTLCOLOREDIT") },
        { WM_CTLCOLORLISTBOX,  _T("WM_CTLCOLORLISTBOX") },
        { WM_CTLCOLORBTN,  _T("WM_CTLCOLORBTN") },
        { WM_CTLCOLORDLG,  _T("WM_CTLCOLORDLG") },
        { WM_CTLCOLORSCROLLBAR,  _T("WM_CTLCOLORSCROLLBAR") },
        { WM_CTLCOLORSTATIC,  _T("WM_CTLCOLORSTATIC") },
        { WM_MOUSEMOVE,  _T("WM_MOUSEMOVE") },
        { WM_LBUTTONDOWN,  _T("WM_LBUTTONDOWN") },
        { WM_LBUTTONUP,  _T("WM_LBUTTONUP") },
        { WM_LBUTTONDBLCLK,  _T("WM_LBUTTONDBLCLK") },
        { WM_RBUTTONDOWN,  _T("WM_RBUTTONDOWN") },
        { WM_RBUTTONUP,  _T("WM_RBUTTONUP") },
        { WM_RBUTTONDBLCLK,  _T("WM_RBUTTONDBLCLK") },
        { WM_MBUTTONDOWN,  _T("WM_MBUTTONDOWN") },
        { WM_MBUTTONUP,  _T("WM_MBUTTONUP") },
        { WM_MBUTTONDBLCLK,  _T("WM_MBUTTONDBLCLK") },
        { WM_MOUSEWHEEL,  _T("WM_MOUSEWHEEL") },
        { WM_XBUTTONDOWN,  _T("WM_XBUTTONDOWN") },
        { WM_XBUTTONUP,  _T("WM_XBUTTONUP") },
        { WM_XBUTTONDBLCLK,  _T("WM_XBUTTONDBLCLK") },
        { WM_PARENTNOTIFY,  _T("WM_PARENTNOTIFY") },
        { WM_ENTERMENULOOP,  _T("WM_ENTERMENULOOP") },
        { WM_EXITMENULOOP,  _T("WM_EXITMENULOOP") },
        { WM_NEXTMENU,  _T("WM_NEXTMENU") },
        { WM_SIZING,  _T("WM_SIZING") },
        { WM_CAPTURECHANGED,  _T("WM_CAPTURECHANGED") },
        { WM_MOVING,  _T("WM_MOVING") },
        { WM_POWERBROADCAST,  _T("WM_POWERBROADCAST") },
        { WM_DEVICECHANGE,  _T("WM_DEVICECHANGE") },
        { WM_MDICREATE,  _T("WM_MDICREATE") },
        { WM_MDIDESTROY,  _T("WM_MDIDESTROY") },
        { WM_MDIACTIVATE,  _T("WM_MDIACTIVATE") },
        { WM_MDIRESTORE,  _T("WM_MDIRESTORE") },
        { WM_MDINEXT,  _T("WM_MDINEXT") },
        { WM_MDIMAXIMIZE,  _T("WM_MDIMAXIMIZE") },
        { WM_MDITILE,  _T("WM_MDITILE") },
        { WM_MDICASCADE,  _T("WM_MDICASCADE") },
        { WM_MDIICONARRANGE,  _T("WM_MDIICONARRANGE") },
        { WM_MDIGETACTIVE,  _T("WM_MDIGETACTIVE") },
        { WM_MDISETMENU,  _T("WM_MDISETMENU") },
        { WM_ENTERSIZEMOVE,  _T("WM_ENTERSIZEMOVE") },
        { WM_EXITSIZEMOVE,  _T("WM_EXITSIZEMOVE") },
        { WM_DROPFILES,  _T("WM_DROPFILES") },
        { WM_MDIREFRESHMENU,  _T("WM_MDIREFRESHMENU") },
        { WM_IME_SETCONTEXT,  _T("WM_IME_SETCONTEXT") },
        { WM_IME_NOTIFY,  _T("WM_IME_NOTIFY") },
        { WM_IME_CONTROL,  _T("WM_IME_CONTROL") },
        { WM_IME_COMPOSITIONFULL,  _T("WM_IME_COMPOSITIONFULL") },
        { WM_IME_SELECT,  _T("WM_IME_SELECT") },
        { WM_IME_CHAR,  _T("WM_IME_CHAR") },
        { WM_IME_REQUEST,  _T("WM_IME_REQUEST") },
        { WM_IME_KEYDOWN,  _T("WM_IME_KEYDOWN") },
        { WM_IME_KEYUP,  _T("WM_IME_KEYUP") },
        { WM_MOUSEHOVER,  _T("WM_MOUSEHOVER") },
        { WM_MOUSELEAVE,  _T("WM_MOUSELEAVE") },
        { WM_NCMOUSEHOVER,  _T("WM_NCMOUSEHOVER") },
        { WM_NCMOUSELEAVE,  _T("WM_NCMOUSELEAVE") },
        { WM_WTSSESSION_CHANGE,  _T("WM_WTSSESSION_CHANGE") },
        { WM_TABLET_FIRST,  _T("WM_TABLET_FIRST") },
        { WM_TABLET_LAST,  _T("WM_TABLET_LAST") },
        { WM_CUT,  _T("WM_CUT") },
        { WM_COPY,  _T("WM_COPY") },
        { WM_PASTE,  _T("WM_PASTE") },
        { WM_CLEAR,  _T("WM_CLEAR") },
        { WM_UNDO,  _T("WM_UNDO") },
        { WM_RENDERFORMAT,  _T("WM_RENDERFORMAT") },
        { WM_RENDERALLFORMATS,  _T("WM_RENDERALLFORMATS") },
        { WM_DESTROYCLIPBOARD,  _T("WM_DESTROYCLIPBOARD") },
        { WM_DRAWCLIPBOARD,  _T("WM_DRAWCLIPBOARD") },
        { WM_PAINTCLIPBOARD,  _T("WM_PAINTCLIPBOARD") },
        { WM_VSCROLLCLIPBOARD,  _T("WM_VSCROLLCLIPBOARD") },
        { WM_SIZECLIPBOARD,  _T("WM_SIZECLIPBOARD") },
        { WM_ASKCBFORMATNAME,  _T("WM_ASKCBFORMATNAME") },
        { WM_CHANGECBCHAIN,  _T("WM_CHANGECBCHAIN") },
        { WM_HSCROLLCLIPBOARD,  _T("WM_HSCROLLCLIPBOARD") },
        { WM_QUERYNEWPALETTE,  _T("WM_QUERYNEWPALETTE") },
        { WM_PALETTEISCHANGING,  _T("WM_PALETTEISCHANGING") },
        { WM_PALETTECHANGED,  _T("WM_PALETTECHANGED") },
        { WM_HOTKEY,  _T("WM_HOTKEY") },
        { WM_PRINT,  _T("WM_PRINT") },
        { WM_PRINTCLIENT,  _T("WM_PRINTCLIENT") },
        { WM_APPCOMMAND,  _T("WM_APPCOMMAND") },
        { WM_THEMECHANGED,  _T("WM_THEMECHANGED") },
        { WM_CLIPBOARDUPDATE,  _T("WM_CLIPBOARDUPDATE") },
        { WM_HANDHELDFIRST,  _T("WM_HANDHELDFIRST") },
        { WM_HANDHELDLAST,  _T("WM_HANDHELDLAST") },
        { WM_AFXFIRST,  _T("WM_AFXFIRST") },
        { WM_AFXLAST,  _T("WM_AFXLAST") },
        { WM_PENWINFIRST,  _T("WM_PENWINFIRST") },
        { WM_PENWINLAST,  _T("WM_PENWINLAST") },
        { WM_APP,  _T("WM_APP") },
        {WM_USER, _T("WM_USER")}
      };
      if (names.cend() == names.find(msg)) return to_tstring(msg);
      return names[msg];
    }
  }
}
