#include "function.h"
int main()
{
    CreateConsoleWindow(1100, 700);
    resizeConsole(1100, 700);
    FixConsoleWindow();
    int snd = 1;
    while (1) {
        _sound(snd);
        if (manhinhchinh(snd) == 1) continue;
        else break;
    }
    return 0;
}
