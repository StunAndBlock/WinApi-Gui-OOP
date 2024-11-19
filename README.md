# WinApi-Gui-OOP
## Easy to setup wrapped WinApi library, for OOP integration and c++17 standard matching 
### Compilation source
- Required:
>MinGW compiler toolchain (e.g., g++).
- Process:
***
Make
***
>>result into creating libraries: static: static/libsan_winapi_gui.a, dynamic: build/san_winapi_gui.dll
### Use
- Compilation your project:
***
g++ -o app.exe main.cpp -L(OMG) [^1] -lsan_winapi_gui -luser32
***
- Code integration:
```
#include "StunAndBlock/WINAPI-GUI-OOP/san_winapi_gui.hpp"
class MyGui : private BaseGui {
public:
    LRESULT SetupWin(RECT rect, HWND hwnd) override {
        ...
        return 0;
    }
    LRESULT __stdcall Handler(HWND hwnd, UINT msg,
                              WPARAM  wParam, LPARAM lParam) override {
        ...
        return DefWindowProcW(hwnd, msg, wParam, lParam);
    }
    void Show() opverride{
        ...
    }
};

int main() {
    MyGui gui;
    gui.Show(); // Display the GUI
    return 0;
}
```

[^1]: path for static/libsan_winapi_gui.a, like -Lmyproject/StunAndBlock/WINAPI-GUI-OOP/static/libsan_winapi_gui.a
