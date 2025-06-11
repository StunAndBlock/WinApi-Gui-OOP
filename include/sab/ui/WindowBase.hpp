#ifndef SAB_WINUI_WINDOWBASE_HPP_
#define SAB_WINUI_WINDOWBASE_HPP_
#include <Windows.h>


#ifdef SAB_WINUI_LIB_EXPORT
#define SAB_WINUI_LIB __declspec(dllexport)
#else
#define SAB_WINUI_LIB __declspec(dllimport)
#endif

namespace sab {
    namespace winui {

        class SAB_WINUI_LIB WindowBase{
            protected:
                HWND hWnd_;
                //camelCase my method
                virtual LRESULT handler(UINT ,WPARAM, LPARAM );
                //PascalCase WinApi integration callback procedure
                static LRESULT __stdcall InitProc(HWND, UINT, WPARAM, LPARAM);
                static LRESULT __stdcall WindowProc(HWND, UINT, WPARAM , LPARAM);
            public:
                WindowBase();
                virtual ~WindowBase() = default;
                virtual void show();
                virtual LRESULT setupWin(RECT, HWND) = 0;
        };

    };
};


#endif //!SAB_UI_WINDOWBASE
