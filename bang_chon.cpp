#include "function.h"
void bangchon(int snd) {
    line_up(43, 15, 30);
    gotoXY(44, 16); cout << "             PLAY            ";
    line_bot(43, 17, 30);
    gotoXY(44, 18); cout << "            BOT PLAY         ";
    line_bot(43, 19, 30);
    gotoXY(44, 20); cout << "            RECORD           ";
    line_bot(43, 21, 30);
    if (snd == 1) {
        gotoXY(44, 22); cout << "            SOUND            ";
    }
    else {
        gotoXY(44, 22); cout << "         SOUND : OFF         ";
    }
    line_bot(43, 23, 30);
    gotoXY(44, 24); cout << "            HELP             ";
    line_bot(43, 25, 30);
    gotoXY(44, 26); cout << "            ABOUT            ";
    line_bot(43, 27, 30);
    gotoXY(44, 28); cout << "            EXIT             ";
    line_down(43, 29, 30);
}