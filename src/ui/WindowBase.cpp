#include "sab/ui/WindowBase.hpp"

/* start of ui-related block
-----------------------------*/
namespace sab {
    namespace winui {

        LRESULT WindowBase::handler(UINT msg,WPARAM wParam, LPARAM lParam){
            switch (msg)
            {
            case WM_CREATE:
                break;
            case WM_CLOSE:
                PostQuitMessage(0);
                break;
            }
            return DefWindowProcW(hWnd_, msg, wParam, lParam);
        }

        LRESULT __stdcall WindowBase::InitProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
            WindowBase* pThis = nullptr;
            if (msg == WM_NCCREATE) {
                CREATESTRUCTW* pCreate = reinterpret_cast<CREATESTRUCTW*>(lParam);
                pThis = reinterpret_cast<WindowBase*>(pCreate->lpCreateParams);
                SetWindowLongPtrW(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pThis));
                SetWindowLongPtrW(hwnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&WindowBase::WindowProc));
                pThis->hWnd_ = hwnd;
                return WindowProc(pThis->hWnd_, msg, wParam, lParam);
            }
            // should return other value. If pThis is nullptr then this is a problem with pointer recasting, this cannot lead into normal behaviour
            // as it leads in this case.
            return DefWindowProcW(hwnd, msg, wParam, lParam);
        }
        LRESULT __stdcall WindowBase::WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
            WindowBase* pThis = reinterpret_cast<WindowBase*>(GetWindowLongPtrW(hwnd, GWLP_USERDATA));
            if (pThis) {
                return pThis->Handler(msg, wParam,lParam);
            }
            // should return other value. If pThis is nullptr then this is a problem with pointer recasting, this cannot lead into normal behaviour
            // as it leads in this case.
            return DefWindowProcW(hwnd, msg, wParam, lParam);
        }
        /* End of ui-related block, start of logic block
        -------------------------------------------------*/

        WindowBase::WindowBase(){
            hWnd_ = NULL;
        }

        void WindowBase::Show(){
            ShowWindow(hWnd_, SW_SHOW);
            UpdateWindow(hWnd_);
        }

    }
}