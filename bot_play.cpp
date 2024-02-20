#include "function.h"
void makebot(int n, vector<vector<int>> &bot) {
    bot[0] = { 1, 2, 1, 3, 2, 3 };
    bot[1] = { 1,3,1,2,3,2 ,1,3,2,1,2,3,1,3 };
    int chan[3][6] = {
    {1, 2, 1, 3, 2, 3 },
    {3,1,3,2,1,2},
    {2, 3, 2, 1, 3, 1},
    };
    int le[3][6] = {
        {1,3,1,2,3,2},
        {2,1,2,3,1,3},
        {3,2,3,1,2,1},
    };
    if (n < 4) return;
    if (n % 2 == 0) {
        for (int i = 2; i <= n-2; i += 2) {
            int const1 = 0, const2 = 0;
            while (const1 < pow(2, i+2) - 1) {
                if (const1 % 4 != 3) {
                    for (int j = 0; j < 6; j++) bot[i].push_back(chan[const2 % 3][j]);
                    const1 += 3; const2 ++;
                }
                else {
                    bot[i].push_back(bot[i - 2][2*(const2 - 1)]);
                    bot[i].push_back(bot[i - 2][2 * const2 - 1]);
                    const1++;
                }
            }
        }
    }
    else {
        for (int i = 3; i <= n-2; i += 2) {
            int const1 = 0, const2 = 0;
            while (const1 < pow(2, i+2) - 1) {
                if (const1 % 4 != 3) {
                    for (int j = 0; j < 6; j++) bot[i].push_back(le[const2 % 3][j]);
                    const1 += 3; const2++;
                }
                else {
                    bot[i].push_back(bot[i - 2][2 * (const2 - 1)]);
                    bot[i].push_back(bot[i - 2][2 * const2 - 1]);
                    const1++;
                }
            }
        }
    }
}
void botplay(int n) {
    Ancontro();
    draw_nen();
    bang_batdau(10);
    vector<vector<int>> bot(8);
    makebot(n, bot);
    vector<vector<int>> v(3);
    int temp1 = 1, temp2 = 1;
    for (int i = n; i > 0; i--) v[0].push_back(i);
    int luot = 0;
    while (1) {
        for (int i = 0; i < v[0].size(); i++) {
            drawthanh(v[0][i], i, 1, 200);
            if (luot == 0) Sleep(100);
        }
        for (int i = 0; i < v[1].size(); i++) {
            drawthanh(v[1][i], i, 2, 200);
            if (luot == 0) Sleep(100);
        }
        for (int i = 0; i < v[2].size(); i++) {
            drawthanh(v[2][i], i, 3, 200);
            if (luot == 0) Sleep(100);
        }
        gotoXY(90, 10); printf("MOVE: %d", luot);
        gotoXY(90, 8); cout << "Press F to pause.";
        if (win(v, n)) {
            nhapnhay(v, n);
            return;
        }
        Sleep(1000);
        temp1 = bot[n - 2][2 * luot]; temp2 = bot[n - 2][2 * luot + 1];
        drawthanh(v[temp1 - 1].back(), v[temp1 - 1].size() - 1, temp1, 160);
        v = chuyen(temp1, temp2, v);
        DrawBox(190, 30, 20, 20 + (temp1 - 1) * 25, 12, 0);
        temp1 = temp2;
        luot++;
        if (_kbhit()) {
            char key = _getch();
            if (key == 'f' || key == 'F') {
                dialog("PAUSING");
                gotoXY(36, 20); SetColor(30);
                cout << "Continue?";
                int cn = 0;
                while (1) {
                    SetColor(100);
                    if (cn % 2 == 0) {
                        gotoXY(54, 24); cout << "YES";
                        SetColor(240); gotoXY(60, 24); cout << "CANCEL";
                    }
                    else {
                        gotoXY(60, 24); cout << "CANCEL";
                        SetColor(240); gotoXY(54, 24); cout << "YES";
                    }
                    char key = _getch();
                    if (key == 75) cn--;
                    if (key == 77) cn++;
                    if (key == 13 && cn % 2 == 0) {
                        draw_nen();
                        break;
                    }
                    if (key == 13 && cn % 2 == 1) return;
                }
            }
        }
        bang_batdau(0, temp1);
    }
}