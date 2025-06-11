# WinApi-Gui-OOP
### Easy to setup wrapped WinApi library, for OOP integration and c++17 standard matching 
## Compile source
### Required:
>MinGW compiler toolchain (e.g., g++).
### Process:
#### dynamic + static
```bash
Make
```
#### <sub>only for dynamic</sub>
```bash
Make dynamic
```
#### only for static
```bash
Make static
```
#### result into creating libraries: 
- static: 
  - build/static/libsab_winui.a 
- dynamic: 
  - build/dynamic/libsab_winui.dll
  - build/dynamic/libsab_winui.dll.a *<sub>if you want dynamic link use this .a, this is import library for dll not static library! libsab_winui.a != libsab_winui.dll.a </sub>*
## Download latest release
### Includes:
- libsab_winui.a
- libsab_winui.dll
- libsab_winui.dll.a
- headers
## Use
### Compile your project:
```bash
g++ -o app.exe main.cpp -L<folder_with_libsab_wibui.dll.a> -lsab_winui.dll
```
Important *-l flag requires import library from <folder_with_libsab_wibui.dll.a>, so it requires libsab_wibui.dll.a, linker will append .a for you so make -lsab_winui.dll for linker to search sab_winui.dll.a*
*Example: g++ -o app.exe main.cpp -Llib -lsab_winui.dll*
### Code integration:
```
#include "sab/ui/WindowBase.hpp"

class Gui : private sab::winui::WindowBase {
public:
    LRESULT setupWin(RECT rect, HWND hwnd) override {
        ...
        return 0;
    }
    LRESULT Handler(UINT msg, WPARAM  wParam, LPARAM lParam) override {
        ...
        return DefWindowProcW(hWnd_, msg, wParam, lParam);
    }
    void show() opverride{
        ...
    }
};

int __stdcall wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
                        LPWSTR lpCmdLine, int nShowCmd){
    Gui test;
    test.init(hInstance, lpCmdLine, nShowCmd);
    RECT wm = {200, 200, 600, 800};
    test.setupWin(wm);
    test.dispatch();

    return 0;
}
```

