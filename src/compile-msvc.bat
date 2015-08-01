@ECHO OFF
cls
cl.exe /nologo /D_USRDLL /D_WINDLL /O2 mirctolk.c Tolk.lib /link /DLL /DEF:mirctolk.def /OUT:mirctolk.dll
pause
