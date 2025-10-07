#include "includes/copyclip.h"
#include "includes/colors.h"
#include "includes/os_detect.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef OS_WINDOWS
#include <windows.h>
#endif

void copy_to_clipboard_any(const char *text) {

#ifdef OS_LINUX
    const char *wayland = getenv("WAYLAND_DISPLAY");
    const char *x11 = getenv("DISPLAY");
    FILE *pipe = NULL;

    if (wayland) {
        pipe = popen("wl-copy", "w");
        if (!pipe) {
            fprintf(stderr, RED "Error: no command wl-copy (Wayland)\n" RESET);
            exit(1);
        }
        fwrite(text, sizeof(char), strlen(text), pipe);
        pclose(pipe);
    } else if (x11) {
        // X11
        pipe = popen("xclip -selection clipboard", "w");
        if (!pipe) {
            fprintf(stderr, RED "Error: no command xclip (X11)\n" RESET);
            exit(1);
        }
        fwrite(text, sizeof(char), strlen(text), pipe);
        pclose(pipe);
    } else {
        fprintf(stderr, RED "Error: no display environment detected (not Wayland or X11)\n" RESET);
        exit(1);
    }

#elif defined(OS_MAC)
    FILE *pipe = popen("pbcopy", "w");
    if (!pipe) {
        fprintf(stderr, RED "Error: command pbcopy not found.\n" RESET);
        exit(1);
    }
    fwrite(text, sizeof(char), strlen(text), pipe);
    pclose(pipe);

#elif defined(OS_WINDOWS)
    const size_t len = strlen(text) + 1;
    HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
    if (!hMem) {
        fprintf(stderr, RED "Error: unable to allocate memory for clipboard.\n" RESET);
        return;
    }
    memcpy(GlobalLock(hMem), text, len);
    GlobalUnlock(hMem);
    if (OpenClipboard(NULL)) {
        EmptyClipboard();
        SetClipboardData(CF_TEXT, hMem);
        CloseClipboard();
    } else {
        fprintf(stderr, RED "Error: could not open clipboard.\n" RESET);
        GlobalFree(hMem);
    }

#else
    fprintf(stderr, RED "Clipboard not supported on this platform.\n" RESET);
#endif
}

