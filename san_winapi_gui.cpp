#include "san_winapi_gui.hpp"

/* start of Gui-related block
-----------------------------*/
LRESULT __stdcall Gui::Handler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
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
LRESULT __stdcall Gui::WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    Gui* pThis = nullptr;
    if (msg == WM_NCCREATE) {
        CREATESTRUCTW* pCreate = reinterpret_cast<CREATESTRUCTW*>(lParam);
        pThis = reinterpret_cast<Gui*>(pCreate->lpCreateParams);
        SetWindowLongPtrW(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pThis));
    } else {
        pThis = reinterpret_cast<Gui*>(GetWindowLongPtrW(hwnd, GWLP_USERDATA));
    }

    if (pThis) {
        return pThis->Handler(hwnd, msg, wParam,lParam);
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}
/* End of Gui-related block, start of logic block
-------------------------------------------------*/

Gui::Gui(){
    hMain_ = NULL;
}

void Gui::Show(){
    ShowWindow(hMain_, SW_SHOW);
    UpdateWindow(hMain_);
}