#include "function.h"
void YesNoHighlight(int k)
{
    switch (k)
    {
    case 1:
        DrawFromFile("Yes.txt", 7 * 16 + 12, 30, 28);
        DrawFromFile("No.txt", 10, 80, 28);
        break;
    case 2:
        DrawFromFile("Yes.txt", 10, 30, 28);
        DrawFromFile("No.txt", 7 * 16 + 12, 80, 28);
        break;
    }
}
int AskContinueAction()
{
    DrawFromFile("Yes.txt", 7 * 16 + 12, 30, 28);
    fflush(stdin);
    int k = 1;
    do
    {
        int cmd = toupper(_getch());
        if ((cmd == 'D' || cmd == ARROW_RIGHT) && k < 2)
        {
            k++;
            YesNoHighlight(k);
        }
        else if ((cmd == 'A' || cmd == ARROW_LEFT) && k > 1)
        {
            k--;
            YesNoHighlight(k);
        }
        else if (cmd == KEY_ENTER)
        {
            return k;
            break;
        }
    } while (1);
}
int AskContinueBox(bool may)
{
    int kq = 0;
    DrawBox(16, 100, 30, 10, 10, 30);
    DrawFromFile("Continue.txt", 100, 25, 12);
    DrawFromFile("Yes.txt", 10, 30, 28);
    DrawFromFile("No.txt", 10, 80, 28);
    int Action = AskContinueAction();
    if (Action == 1) {
        system("cls");
        return 0;
    }
    else if (Action == 2) {
        system("cls");
        return 1;
    }
}
void draw_win() {
    DrawFromFile("win.txt", 80, 45, 10);
    gotoXY(45, 35); cout << "Press F to play again.";
    return;
}