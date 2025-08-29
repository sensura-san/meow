#include <stdio.h>
#include <locale.h>

#if defined(_WIN32)
#include <windows.h>
#include <fcntl.h>
#include <io.h>
#endif

int main(void) {
    // Set UTF-8 locale for Linux/WSL
    setlocale(LC_ALL, "");

#if defined(_WIN32)
    // Set Windows console to UTF-8
    SetConsoleOutputCP(CP_UTF8);
    _setmode(_fileno(stdout), _O_U8TEXT);

    // Wide string literal for Windows
    const wchar_t *meow_art =
        L"┌───────┐\n"
        L"│ mrrp~ │\n"
        L"└───────┘\n"
        L"          ╱| 、         ／l、\n"
        L"        （˚､. ７      （˚､ ｡ ７\n"
        L"         |、~〵         l  ~ヽ\n"
        L"         じしL)__ノ     じしf_)_ノ\n";

    wprintf(L"%ls", meow_art);
#else
    // Normal UTF-8 string for Linux/WSL
    const char *meow_art =
        "┌───────┐\n"
        "│ mrrp~ │\n"
        "└───────┘\n"
        "          ╱| 、         ／l、\n"
        "        （˚､. ７      （˚､ ｡ ７\n"
        "         |、~〵         l  ~ヽ\n"
        "         じしL)__ノ     じしf_)_ノ\n";

    printf("%s", meow_art);
#endif

    return 0;
}
