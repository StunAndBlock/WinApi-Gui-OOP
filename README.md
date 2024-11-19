# WinApi-Gui-OOP
## Easy to setup wrapped WinApi library, for OOP integration and c++17 standard matching 
### Compilation
- Required:
>MinGW compiler toolchain (e.g., g++).
- Process:

```
Make
```
>>result into creating libraries: static: static/libsan_winapi_gui.a, dynamic: build/san_winapi_gui.dll
### Use
```
g++ -o app.exe main.cpp -L(OMG) [^1] -lsan_winapi_gui -luser32
```


[^1]: path for static/libsan_winapi_gui.a, like -Lmyproject/StunAndBlock/WINAPI-GUI-OOP/static/libsan_winapi_gui.a