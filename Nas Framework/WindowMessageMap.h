#pragma once
#include <unordered_map>
#include <sstream>
#include "NasWin.h"

class WindowsMessageMap
{
public:
	WindowsMessageMap()
	{
		mm[WM_NULL]							= L"WM_NULL";
		mm[WM_CREATE]						= L"WM_CREATE";
		mm[WM_DESTROY]						= L"WM_DESTROY";
		mm[WM_MOVE]							= L"WM_MOVE";
		mm[WM_SIZE]							= L"WM_SIZE";
		mm[WM_ACTIVATE]						= L"WM_ACTIVATE";
		mm[WM_SETFOCUS]						= L"WM_SETFOCUS";
		mm[WM_KILLFOCUS]					= L"WM_KILLFOCUS";
		mm[WM_ENABLE]						= L"WM_ENABLE";
		mm[WM_SETREDRAW]					= L"WM_SETREDRAW";
		mm[WM_SETTEXT]						= L"WM_SETTEXT";
		mm[WM_GETTEXT]						= L"WM_GETTEXT";
		mm[WM_GETTEXTLENGTH]				= L"WM_GETTEXTLENGTH";
		mm[WM_PAINT]						= L"WM_PAINT";
		mm[WM_CLOSE]						= L"WM_CLOSE";
		mm[WM_QUERYENDSESSION]				= L"WM_QUERYENDSESSION";
		mm[WM_QUIT]							= L"WM_QUIT";
		mm[WM_QUERYOPEN]					= L"WM_QUERYOPEN";
		mm[WM_ERASEBKGND]					= L"WM_ERASEBKGND";
		mm[WM_SYSCOLORCHANGE]				= L"WM_SYSCOLORCHANGE";
		mm[WM_ENDSESSION]					= L"WM_ENDSESSION";
		mm[WM_SHOWWINDOW]					= L"WM_SHOWWINDOW";
		mm[WM_WININICHANGE]					= L"WM_WININICHANGE";
		mm[WM_DEVMODECHANGE]				= L"WM_DEVMODECHANGE";
		mm[WM_ACTIVATEAPP]					= L"WM_ACTIVATEAPP";
		mm[WM_FONTCHANGE]					= L"WM_FONTCHANGE";
		mm[WM_TIMECHANGE]					= L"WM_TIMECHANGE";
		mm[WM_CANCELMODE]					= L"WM_CANCELMODE";
		mm[WM_SETCURSOR]					= L"WM_SETCURSOR";
		mm[WM_MOUSEACTIVATE]				= L"WM_MOUSEACTIVATE";
		mm[WM_CHILDACTIVATE]				= L"WM_CHILDACTIVATE";
		mm[WM_QUEUESYNC]					= L"WM_QUEUESYNC";
		mm[WM_GETMINMAXINFO]				= L"WM_GETMINMAXINFO";
		mm[WM_PAINTICON]					= L"WM_PAINTICON";
		mm[WM_ICONERASEBKGND]				= L"WM_ICONERASEBKGND";
		mm[WM_NEXTDLGCTL]					= L"WM_NEXTDLGCTL";
		mm[WM_SPOOLERSTATUS]				= L"WM_SPOOLERSTATUS";
		mm[WM_DRAWITEM]						= L"WM_DRAWITEM";
		mm[WM_MEASUREITEM]					= L"WM_MEASUREITEM";
		mm[WM_DELETEITEM]					= L"WM_DELETEITEM";
		mm[WM_VKEYTOITEM]					= L"WM_VKEYTOITEM";
		mm[WM_CHARTOITEM]					= L"WM_CHARTOITEM";
		mm[WM_SETFONT]						= L"WM_SETFONT";
		mm[WM_GETFONT]						= L"WM_GETFONT";
		mm[WM_SETHOTKEY]					= L"WM_SETHOTKEY";
		mm[WM_GETHOTKEY]					= L"WM_GETHOTKEY";
		mm[WM_QUERYDRAGICON]				= L"WM_QUERYDRAGICON";
		mm[WM_COMPAREITEM]					= L"WM_COMPAREITEM";
		mm[WM_GETOBJECT]					= L"WM_GETOBJECT";
		mm[WM_COMPACTING]					= L"WM_COMPACTING";
		mm[WM_COMMNOTIFY]					= L"WM_COMMNOTIFY";
		mm[WM_WINDOWPOSCHANGING]			= L"WM_WINDOWPOSCHANGING";
		mm[WM_WINDOWPOSCHANGED]				= L"WM_WINDOWPOSCHANGED";
		mm[WM_POWER]						= L"WM_POWER";
		mm[WM_COPYDATA]						= L"WM_COPYDATA";
		mm[WM_CANCELJOURNAL]				= L"WM_CANCELJOURNAL";
		mm[WM_NOTIFY]						= L"WM_NOTIFY";
		mm[WM_INPUTLANGCHANGEREQUEST]		= L"WM_INPUTLANGCHANGEREQUEST";
		mm[WM_INPUTLANGCHANGE]				= L"WM_INPUTLANGCHANGE";
		mm[WM_TCARD]						= L"WM_TCARD";
		mm[WM_HELP]							= L"WM_HELP";
		mm[WM_USERCHANGED]					= L"WM_USERCHANGED";
		mm[WM_NOTIFYFORMAT]					= L"WM_NOTIFYFORMAT";
		mm[WM_CONTEXTMENU]					= L"WM_CONTEXTMENU";
		mm[WM_STYLECHANGING]				= L"WM_STYLECHANGING";
		mm[WM_STYLECHANGED]					= L"WM_STYLECHANGED";
		mm[WM_DISPLAYCHANGE]				= L"WM_DISPLAYCHANGE";
		mm[WM_GETICON]						= L"WM_GETICON";
		mm[WM_SETICON]						= L"WM_SETICON";
		mm[WM_NCCREATE]						= L"WM_NCCREATE";
		mm[WM_NCDESTROY]					= L"WM_NCDESTROY";
		mm[WM_NCCALCSIZE]					= L"WM_NCCALCSIZE";
		mm[WM_NCHITTEST]					= L"WM_NCHITTEST";
		mm[WM_NCPAINT]						= L"WM_NCPAINT";
		mm[WM_NCACTIVATE]					= L"WM_NCACTIVATE";
		mm[WM_GETDLGCODE]					= L"WM_GETDLGCODE";
		mm[WM_SYNCPAINT]					= L"WM_SYNCPAINT";
		mm[WM_NCMOUSEMOVE]					= L"WM_NCMOUSEMOVE";
		mm[WM_NCLBUTTONDOWN]				= L"WM_NCLBUTTONDOWN";
		mm[WM_NCLBUTTONUP]					= L"WM_NCLBUTTONUP";
		mm[WM_NCLBUTTONDBLCLK]				= L"WM_NCLBUTTONDBLCLK";
		mm[WM_NCRBUTTONDOWN]				= L"WM_NCRBUTTONDOWN";
		mm[WM_NCRBUTTONUP]					= L"WM_NCRBUTTONUP";
		mm[WM_NCRBUTTONDBLCLK]				= L"WM_NCRBUTTONDBLCLK";
		mm[WM_NCMBUTTONDOWN]				= L"WM_NCMBUTTONDOWN";
		mm[WM_NCMBUTTONUP]					= L"WM_NCMBUTTONUP";
		mm[WM_NCMBUTTONDBLCLK]				= L"WM_NCMBUTTONDBLCLK";
		mm[WM_NCXBUTTONDOWN]				= L"WM_NCXBUTTONDOWN";
		mm[WM_NCXBUTTONUP]					= L"WM_NCXBUTTONUP";
		mm[WM_NCXBUTTONDBLCLK]				= L"WM_NCXBUTTONDBLCLK";
		mm[EM_GETSEL]						= L"EM_GETSEL";
		mm[EM_SETSEL]						= L"EM_SETSEL";
		mm[EM_GETRECT]						= L"EM_GETRECT";
		mm[EM_SETRECT]						= L"EM_SETRECT";
		mm[EM_SETRECTNP]					= L"EM_SETRECTNP";
		mm[EM_SCROLL]						= L"EM_SCROLL";
		mm[EM_LINESCROLL]					= L"EM_LINESCROLL";
		mm[EM_SCROLLCARET]					= L"EM_SCROLLCARET";
		mm[EM_GETMODIFY]					= L"EM_GETMODIFY";
		mm[EM_SETMODIFY]					= L"EM_SETMODIFY";
		mm[EM_GETLINECOUNT]					= L"EM_GETLINECOUNT";
		mm[EM_LINEINDEX]					= L"EM_LINEINDEX";
		mm[EM_SETHANDLE]					= L"EM_SETHANDLE";
		mm[EM_GETHANDLE]					= L"EM_GETHANDLE";
		mm[EM_GETTHUMB]						= L"EM_GETTHUMB";
		mm[EM_LINELENGTH]					= L"EM_LINELENGTH";
		mm[EM_REPLACESEL]					= L"EM_REPLACESEL";
		mm[EM_GETLINE]						= L"EM_GETLINE";
		mm[EM_LIMITTEXT]					= L"EM_LIMITTEXT";
		mm[EM_SETLIMITTEXT]					= L"EM_SETLIMITTEXT";
		mm[EM_CANUNDO]						= L"EM_CANUNDO";
		mm[EM_UNDO]							= L"EM_UNDO";
		mm[EM_FMTLINES]						= L"EM_FMTLINES";
		mm[EM_LINEFROMCHAR]					= L"EM_LINEFROMCHAR";
		mm[EM_SETTABSTOPS]					= L"EM_SETTABSTOPS";
		mm[EM_SETPASSWORDCHAR]				= L"EM_SETPASSWORDCHAR";
		mm[EM_EMPTYUNDOBUFFER]				= L"EM_EMPTYUNDOBUFFER";
		mm[EM_GETFIRSTVISIBLELINE]			= L"EM_GETFIRSTVISIBLELINE";
		mm[EM_SETREADONLY]					= L"EM_SETREADONLY";
		mm[EM_SETWORDBREAKPROC]				= L"EM_SETWORDBREAKPROC";
		mm[EM_GETWORDBREAKPROC]				= L"EM_GETWORDBREAKPROC";
		mm[EM_GETPASSWORDCHAR]				= L"EM_GETPASSWORDCHAR";
		mm[EM_SETMARGINS]					= L"EM_SETMARGINS";
		mm[EM_GETMARGINS]					= L"EM_GETMARGINS";
		mm[EM_GETLIMITTEXT]					= L"EM_GETLIMITTEXT";
		mm[EM_POSFROMCHAR]					= L"EM_POSFROMCHAR";
		mm[EM_CHARFROMPOS]					= L"EM_CHARFROMPOS";
		mm[EM_SETIMESTATUS]					= L"EM_SETIMESTATUS";
		mm[EM_GETIMESTATUS]					= L"EM_GETIMESTATUS";
		mm[SBM_SETPOS]						= L"SBM_SETPOS";
		mm[SBM_GETPOS]						= L"SBM_GETPOS";
		mm[SBM_SETRANGE]					= L"SBM_SETRANGE";
		mm[SBM_GETRANGE]					= L"SBM_GETRANGE";
		mm[SBM_ENABLE_ARROWS]				= L"SBM_ENABLE_ARROWS";
		mm[SBM_SETRANGEREDRAW]				= L"SBM_SETRANGEREDRAW";
		mm[SBM_SETSCROLLINFO]				= L"SBM_SETSCROLLINFO";
		mm[SBM_GETSCROLLINFO]				= L"SBM_GETSCROLLINFO";
		mm[SBM_GETSCROLLBARINFO]			= L"SBM_GETSCROLLBARINFO";
		mm[BM_GETCHECK]						= L"BM_GETCHECK";
		mm[BM_SETCHECK]						= L"BM_SETCHECK";
		mm[BM_GETSTATE]						= L"BM_GETSTATE";
		mm[BM_SETSTATE]						= L"BM_SETSTATE";
		mm[BM_SETSTYLE]						= L"BM_SETSTYLE";
		mm[BM_CLICK]						= L"BM_CLICK";
		mm[BM_GETIMAGE]						= L"BM_GETIMAGE";
		mm[BM_SETIMAGE]						= L"BM_SETIMAGE";
		mm[BM_SETDONTCLICK]					= L"BM_SETDONTCLICK";
		mm[WM_INPUT]						= L"WM_INPUT";
		mm[WM_KEYDOWN]						= L"WM_KEYDOWN";
		mm[WM_KEYFIRST]						= L"WM_KEYFIRST";
		mm[WM_KEYUP]						= L"WM_KEYUP";
		mm[WM_CHAR]							= L"WM_CHAR";
		mm[WM_DEADCHAR]						= L"WM_DEADCHAR";
		mm[WM_SYSKEYDOWN]					= L"WM_SYSKEYDOWN";
		mm[WM_SYSKEYUP]						= L"WM_SYSKEYUP";
		mm[WM_SYSCHAR]						= L"WM_SYSCHAR";
		mm[WM_SYSDEADCHAR]					= L"WM_SYSDEADCHAR";
		mm[WM_UNICHAR / WM_KEYLAST]			= L"WM_UNICHAR / WM_KEYLAST";
		mm[WM_IME_STARTCOMPOSITION]			= L"WM_IME_STARTCOMPOSITION";
		mm[WM_IME_ENDCOMPOSITION]			= L"WM_IME_ENDCOMPOSITION";
		mm[WM_IME_COMPOSITION]				= L"WM_IME_COMPOSITION";
		mm[WM_IME_KEYLAST]					= L"WM_IME_KEYLAST";
		mm[WM_INITDIALOG]					= L"WM_INITDIALOG";
		mm[WM_COMMAND]						= L"WM_COMMAND";
		mm[WM_SYSCOMMAND]					= L"WM_SYSCOMMAND";
		mm[WM_TIMER]						= L"WM_TIMER";
		mm[WM_HSCROLL]						= L"WM_HSCROLL";
		mm[WM_VSCROLL]						= L"WM_VSCROLL";
		mm[WM_INITMENU]						= L"WM_INITMENU";
		mm[WM_INITMENUPOPUP]				= L"WM_INITMENUPOPUP";
		mm[WM_MENUSELECT]					= L"WM_MENUSELECT";
		mm[WM_MENUCHAR]						= L"WM_MENUCHAR";
		mm[WM_ENTERIDLE]					= L"WM_ENTERIDLE";
		mm[WM_MENURBUTTONUP]				= L"WM_MENURBUTTONUP";
		mm[WM_MENUDRAG]						= L"WM_MENUDRAG";
		mm[WM_UNINITMENUPOPUP]				= L"WM_UNINITMENUPOPUP";
		mm[WM_CTLCOLORLISTBOX]				= L"WM_CTLCOLORLISTBOX";
		mm[WM_CTLCOLORSTATIC]				= L"WM_CTLCOLORSTATIC";
		mm[WM_CTLCOLORMSGBOX]				= L"WM_CTLCOLORMSGBOX";
		mm[WM_CHANGEUISTATE]				= L"WM_CHANGEUISTATE";
		mm[WM_MENUGETOBJECT]				= L"WM_MENUGETOBJECT";
		mm[WM_LBUTTONDBLCLK]				= L"WM_LBUTTONDBLCLK";
		mm[WM_RBUTTONDBLCLK]				= L"WM_RBUTTONDBLCLK";
		mm[WM_MBUTTONDBLCLK]				= L"WM_MBUTTONDBLCLK";
		mm[WM_UPDATEUISTATE]				= L"WM_UPDATEUISTATE";
		mm[WM_ENTERMENULOOP]				= L"WM_ENTERMENULOOP";
		mm[WM_XBUTTONDBLCLK]				= L"WM_XBUTTONDBLCLK";
		mm[WM_QUERYUISTATE]					= L"WM_QUERYUISTATE";
		mm[WM_PARENTNOTIFY]					= L"WM_PARENTNOTIFY";
		mm[WM_CTLCOLOREDIT]					= L"WM_CTLCOLOREDIT";
		mm[WM_CTLCOLORBTN]					= L"WM_CTLCOLORBTN";
		mm[WM_MENUCOMMAND]					= L"WM_MENUCOMMAND";
		mm[WM_CTLCOLORDLG]					= L"WM_CTLCOLORDLG";
		mm[WM_LBUTTONDOWN]					= L"WM_LBUTTONDOWN";
		mm[WM_MOUSEHWHEEL]					= L"WM_MOUSEHWHEEL";
		mm[WM_XBUTTONDOWN]					= L"WM_XBUTTONDOWN";
		mm[WM_MBUTTONDOWN]					= L"WM_MBUTTONDOWN";
		mm[WM_RBUTTONDOWN]					= L"WM_RBUTTONDOWN";
		mm[WM_CTLCOLORSCROLLBAR]			= L"WM_CTLCOLORSCROLLBAR";
		mm[WM_MOUSEWHEEL]					= L"WM_MOUSEWHEEL";
		mm[WM_MOUSEFIRST]					= L"WM_MOUSEFIRST";
		mm[WM_MOUSEMOVE]					= L"WM_MOUSEMOVE";
		mm[WM_LBUTTONUP]					= L"WM_LBUTTONUP";
		mm[WM_RBUTTONUP]					= L"WM_RBUTTONUP";
		mm[WM_MBUTTONUP]					= L"WM_MBUTTONUP";
		mm[WM_XBUTTONUP]					= L"WM_XBUTTONUP";
		mm[WM_MOUSELAST]					= L"WM_MOUSELAST";
		mm[WM_EXITMENULOOP]					= L"WM_EXITMENULOOP";
		mm[WM_NEXTMENU]						= L"WM_NEXTMENU";
		mm[WM_SIZING]						= L"WM_SIZING";
		mm[WM_CAPTURECHANGED]				= L"WM_CAPTURECHANGED";
		mm[WM_MOVING]						= L"WM_MOVING";
		mm[WM_POWERBROADCAST]				= L"WM_POWERBROADCAST";
		mm[WM_DEVICECHANGE]					= L"WM_DEVICECHANGE";
		mm[WM_MDICREATE]					= L"WM_MDICREATE";
		mm[WM_MDIDESTROY]					= L"WM_MDIDESTROY";
		mm[WM_MDIACTIVATE]					= L"WM_MDIACTIVATE";
		mm[WM_MDIRESTORE]					= L"WM_MDIRESTORE";
		mm[WM_MDINEXT]						= L"WM_MDINEXT";
		mm[WM_MDIMAXIMIZE]					= L"WM_MDIMAXIMIZE";
		mm[WM_MDITILE]						= L"WM_MDITILE";
		mm[WM_MDICASCADE]					= L"WM_MDICASCADE";
		mm[WM_MDIICONARRANGE]				= L"WM_MDIICONARRANGE";
		mm[WM_MDIGETACTIVE]					= L"WM_MDIGETACTIVE";
		mm[WM_MDISETMENU]					= L"WM_MDISETMENU";
		mm[WM_ENTERSIZEMOVE]				= L"WM_ENTERSIZEMOVE";
		mm[WM_EXITSIZEMOVE]					= L"WM_EXITSIZEMOVE";
		mm[WM_DROPFILES]					= L"WM_DROPFILES";
		mm[WM_MDIREFRESHMENU]				= L"WM_MDIREFRESHMENU";
		mm[WM_IME_SETCONTEXT]				= L"WM_IME_SETCONTEXT";
		mm[WM_IME_NOTIFY]					= L"WM_IME_NOTIFY";
		mm[WM_IME_CONTROL]					= L"WM_IME_CONTROL";
		mm[WM_IME_COMPOSITIONFULL]			= L"WM_IME_COMPOSITIONFULL";
		mm[WM_IME_SELECT]					= L"WM_IME_SELECT";
		mm[WM_IME_CHAR]						= L"WM_IME_CHAR";
		mm[WM_IME_REQUEST]					= L"WM_IME_REQUEST";
		mm[WM_IME_KEYDOWN]					= L"WM_IME_KEYDOWN";
		mm[WM_IME_KEYUP]					= L"WM_IME_KEYUP";
		mm[WM_NCMOUSEHOVER]					= L"WM_NCMOUSEHOVE";
		mm[WM_MOUSEHOVER]					= L"WM_MOUSEHOVER";
		mm[WM_NCMOUSELEAVE]					= L"WM_NCMOUSELEAV";
		mm[WM_MOUSELEAVE]					= L"WM_MOUSELEAVE";
		mm[WM_CUT]							= L"WM_CUT";
		mm[WM_PASTE]						= L"WM_PASTE";
		mm[WM_COPY]							= L"WM_COPY";
		mm[WM_UNDO]							= L"WM_UNDO";
		mm[WM_CLEAR]						= L"WM_CLEAR";
		mm[WM_RENDERFORMAT]					= L"WM_RENDERFORMA";
		mm[WM_RENDERALLFORMATS]				= L"WM_RENDERALLFORMATS";
		mm[WM_DESTROYCLIPBOARD]				= L"WM_DESTROYCLIPBOARD";
		mm[WM_DRAWCLIPBOARD]				= L"WM_DRAWCLIPBOARD";
		mm[WM_PAINTCLIPBOARD]				= L"WM_PAINTCLIPBOARD";
		mm[WM_VSCROLLCLIPBOARD]				= L"WM_VSCROLLCLIPBOARD";
		mm[WM_SIZECLIPBOARD]				= L"WM_SIZECLIPBOARD";
		mm[WM_ASKCBFORMATNAME]				= L"WM_ASKCBFORMATNAME";
		mm[WM_CHANGECBCHAIN]				= L"WM_CHANGECBCHAIN";
		mm[WM_HSCROLLCLIPBOARD]				= L"WM_HSCROLLCLIPBOARD";
		mm[WM_QUERYNEWPALETTE]				= L"WM_QUERYNEWPALETTE";
		mm[WM_PALETTEISCHANGING]			= L"WM_PALETTEISCHANGING";
		mm[WM_PALETTECHANGED]				= L"WM_PALETTECHANGED";
		mm[WM_HOTKEY]						= L"WM_HOTKEY";
		mm[WM_PRINT]						= L"WM_PRINT";
		mm[WM_PRINTCLIENT]					= L"WM_PRINTCLIENT";
		mm[WM_APPCOMMAND]					= L"WM_APPCOMMAND";
		mm[WM_HANDHELDFIRST]				= L"WM_HANDHELDFIRST";
		mm[WM_HANDHELDLAST]					= L"WM_HANDHELDLAST";
		mm[WM_AFXFIRST]						= L"WM_AFXFIRST";
		mm[WM_AFXLAST]						= L"WM_AFXLAST";
		mm[WM_PENWINFIRST]					= L"WM_PENWINFIRST";
		mm[WM_PENWINLAST]					= L"WM_PENWINLAST";
		mm[DM_GETDEFID]						= L"DM_GETDEFID";
		mm[WM_USER]							= L"WM_USER";
		mm[DM_SETDEFID]						= L"DM_SETDEFID";
		mm[DM_REPOSITION]					= L"DM_REPOSITION";
		mm[WM_APP]							= L"WM_APP";
	}
	void operator()(MSG msg)
	{
		std::wostringstream ss;
		wchar_t className[128];
		GetClassNameW(msg.hwnd, className, 128);
		ss << className << '\t' << mm[msg.message] << '\t' << msg.lParam << '\t\t\t' << msg.wParam;
		OutputDebugStringW(ss.str().c_str());
	}

private:
	// no need to create hash or equal_to functors, since they're defined for int32_t
	std::unordered_map<UINT, std::wstring, 
		std::hash<UINT>, std::equal_to<UINT>> mm;
};