@ECHO OFF
cls
gcc -s -shared -Wl,--add-stdcall-alias -O3 mirctolk.c -o mirctolk.dll Tolk.dll
pause
