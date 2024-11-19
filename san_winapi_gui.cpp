#include "san_winapi_gui.hpp"

/* start of Gui-related block
-----------------------------*/
LRESULT __stdcall GuiBase::Handler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
    switch (msg)
    {
    case WM_CREATE:
        break;
    case WM_CLOSE:
        PostQuitMessage(0);
        break;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}
LRESULT __stdcall GuiBase::WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    GuiBase* pThis = nullptr;
    if (msg == WM_NCCREATE) {
        CREATESTRUCTW* pCreate = reinterpret_cast<CREATESTRUCTW*>(lParam);
        pThis = reinterpret_cast<GuiBase*>(pCreate->lpCreateParams);
        SetWindowLongPtrW(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pThis));
    } else {
        pThis = reinterpret_cast<GuiBase*>(GetWindowLongPtrW(hwnd, GWLP_USERDATA));
    }

    if (pThis) {
        return pThis->Handler(hwnd, msg, wParam,lParam);
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}
/* End of Gui-related block, start of logic block
-------------------------------------------------*/

GuiBase::GuiBase(){
    hMain_ = NULL;
}

void GuiBase::Show(){
    ShowWindow(hMain_, SW_SHOW);
    UpdateWindow(hMain_);
}