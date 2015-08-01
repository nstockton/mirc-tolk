/* mIRC library to wrap Tolk
 * Licensed under the terms of the GNU Lesser General Public License (LGPL), V3.0
 * (C) 2015 Nick Stockton <nstockton@gmail.com>
*/

#define UNICODE

#include <stdio.h>
#include <windows.h>

#include "Tolk.h"

#if defined(_WIN32) && defined(__MINGW32__) && !defined(__NO_ISOCEXT)
    #define FMT_SWPRINTF snwprintf
#else
    #define FMT_SWPRINTF swprintf
#endif

#define MIRC_DLL_UNLOAD 0
#define MIRC_DLL_TIMEOUT 1
#define MIRC_DLL_EXIT 2

#define MIRC_RETURN_HALT 0
#define MIRC_RETURN_CONTINUE 1
#define MIRC_RETURN_PROCESS 2
#define MIRC_RETURN_DATA 3

typedef struct {
    DWORD mVersion;
    HWND mHwnd;
    BOOL mKeep;
    BOOL mUnicode;
} LOADINFO;

void __declspec(dllexport) __stdcall LoadDll(LOADINFO *lInfo) {
    lInfo->mKeep = TRUE;
    lInfo->mUnicode = TRUE;
    Tolk_Load();
}

int __declspec(dllexport) __stdcall UnloadDll(int mTimeout) {
    if (mTimeout == MIRC_DLL_TIMEOUT) {
        return 0;
    }
    Tolk_Unload();
    return 1;
}

int __declspec(dllexport) __stdcall output(HWND mWnd, HWND aWnd, wchar_t *data, wchar_t *parms, BOOL show, BOOL nopause) {
    Tolk_Output(data, FALSE);
    return MIRC_RETURN_CONTINUE;
}

int __declspec(dllexport) __stdcall output_interrupt(HWND mWnd, HWND aWnd, wchar_t *data, wchar_t *parms, BOOL show, BOOL nopause) {
    Tolk_Output(data, TRUE);
    return MIRC_RETURN_CONTINUE;
}

int __declspec(dllexport) __stdcall speak(HWND mWnd, HWND aWnd, wchar_t *data, wchar_t *parms, BOOL show, BOOL nopause) {
    Tolk_Speak(data, FALSE);
    return MIRC_RETURN_CONTINUE;
}

int __declspec(dllexport) __stdcall speak_interrupt(HWND mWnd, HWND aWnd, wchar_t *data, wchar_t *parms, BOOL show, BOOL nopause) {
    Tolk_Speak(data, TRUE);
    return MIRC_RETURN_CONTINUE;
}

int __declspec(dllexport) __stdcall silence(HWND mWnd, HWND aWnd, wchar_t *data, wchar_t *parms, BOOL show, BOOL nopause) {
    Tolk_Silence();
    return MIRC_RETURN_CONTINUE;
}

int __declspec(dllexport) __stdcall braille(HWND mWnd, HWND aWnd, wchar_t *data, wchar_t *parms, BOOL show, BOOL nopause) {
    Tolk_Braille(data);
    return MIRC_RETURN_CONTINUE;
}

int __declspec(dllexport) __stdcall detect_screenreader(HWND mWnd, HWND aWnd, wchar_t *data, wchar_t *parms, BOOL show, BOOL nopause) {
    const wchar_t *name = Tolk_DetectScreenReader();
    if (name == NULL) {
        FMT_SWPRINTF(data, 2, L"\0");
    }
    else {
        FMT_SWPRINTF(data, sizeof(name) + 1, name);
    }
    return MIRC_RETURN_DATA;
}
