#include "function.h"
vector<vector<int>> chuyen(int x, int y, vector<vector<int>> v)
{
    v[y - 1].push_back(v[x - 1][v[x - 1].size() - 1]);
    v[x - 1].pop_back();
    gotoXY(31 + (y - 1) * 25, 33); b_color(to_string(y), 78);
    gotoXY(31 * (x - 1) * 25, 33); cout << x;
    HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleColor, 240);
    return v;
}
void bang_batdau(int delay, int y) {
    HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleColor, 240);
    DrawBox(190, 200, 1, 0, 33, 0); //to dong duoi 1 2 3
    DrawBox(50, 3, 20, 30, 10, delay);
    gotoXY(31, 33); cout << 1;
    DrawBox(50, 3, 20, 55, 10, delay);
    gotoXY(56, 33); cout << 2;
    DrawBox(50, 3, 20, 80, 10, delay);
    gotoXY(81, 33); cout << 3;
    gotoXY(31 + (y - 1) * 25, 33); b_color(to_string(y), 78);
}
int cach_chuyen(int temp, int color) {
    while (1) {
        char key = _getch();
        if (key == 'd' && temp < 3) {
            gotoXY(31 + (temp - 1) * 25, 33); cout << temp;
            gotoXY(31 + (temp) * 25, 33); b_color(to_string(temp + 1), color);
            temp++;
        }
        else if (key == 'a' && temp > 1) {
            gotoXY(31 + (temp - 1) * 25, 33); cout << temp;
            gotoXY(31 + (temp - 2) * 25, 33); b_color(to_string(temp - 1), color);
            temp--;
        }
        else if (key == 13) {
            gotoXY(31 + (temp - 1) * 25, 33); b_color(to_string(temp), 50);
            HANDLE hConsoleColor;
            hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsoleColor, 240);
            return temp;
        }
        if (key == 8) {
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
                        return 0;
                    }
                    if (key == 13 && cn % 2 == 1) return -1;
                }
        }
        HANDLE hConsoleColor;
        hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsoleColor, 240);
    }
}
bool win(vector<vector<int>> v, int n) {
    if (v[2].size() == n) return true;
    return false;
}
void nhapnhay(vector<vector<int>> v, int n) {
    int t = 0;
    while (t < 5) {
        for (int i = 0; i < v[2].size(); i++) {
            drawthanh(v[2][i], i, 3, 140);
        }
        Sleep(200);
        for (int i = 0; i < v[2].size(); i++) {
            drawthanh(v[2][i], i, 3, 200);
        }
        Sleep(200);
        t++;
    }
}
void timer(int& kq, int &tg)
{
    int t = 0, p = 0;
    while (kq == -2) {
        if ((t > 0 && t % 10 == 0) || (p > 0 && t == 0)) {
            gotoXY(90, 12);
            cout << "Time: ";
            if (p < 10) cout << "0" << p << " : ";
            else cout << p << " : ";
            if (t < 10) cout << "0" << t << "  ";
            else cout << t;
        }
        if (t < 59) t++;
        else {
            t = 0;
            p++;
        }
        Sleep(1000);
    }
    tg = p * 60 + t;
    gotoXY(45, 34); cout << "Your time is: " << p << " p : " << t << " s";
}
void bat_dau(int n, int& luot, int& kq) {
    Ancontro();
    draw_nen();
    bang_batdau(10);
    gotoXY(90, 12); cout << "Time: 00 : 00";
    vector<vector<int>> v(3);
    int temp1 = 1, temp2 = 1;
    for (int i = n; i > 0; i--) v[0].push_back(i);
    luot = 0;
    while (1) {
        for (int i = 0; i < v[0].size(); i++) {
            drawthanh(v[0][i], i, 1);
            if (luot == 0) Sleep(100);
        }
        for (int i = 0; i < v[1].size(); i++) {
            drawthanh(v[1][i], i, 2);
            if (luot == 0) Sleep(100);
        }
        for (int i = 0; i < v[2].size(); i++) {
            drawthanh(v[2][i], i, 3);
            if (luot == 0) Sleep(100);
        }
        gotoXY(90, 10); cout << "MOVE: " << luot;
        gotoXY(90, 8); cout << "Press Backspace to pause.";
        if (win(v, n)) {
            nhapnhay(v, n);
            draw_win(); kq = 0;
            return;
        }
        temp1 = cach_chuyen(temp1, 78);
        if (temp1 == 0) {
            temp1 = 1;
            bang_batdau(0, 1);
            continue;
        }
        if (temp1 == -1) {
            kq = 1; return;
        }
        if (v[temp1 - 1].size() > 0) drawthanh(v[temp1 - 1].back(), v[temp1 - 1].size() - 1, temp1, 160);
        temp2 = cach_chuyen(temp1, 100);
        if (temp2 == 0) {
            temp2 = temp1;
            bang_batdau(0, temp1);
            continue;
        }
        if (temp2 == -1) {
            kq = 1; return;
        }
        if (temp1 == temp2 || v[temp1 - 1].size() == 0 || ((v[temp2 - 1].size() > 0) && v[temp1 - 1].back() > v[temp2 - 1].back())) {
            gotoXY(10, 4); cout << "INVALID MOVE!";
            if (v[temp1 - 1].size() > 0) drawthanh(v[temp1 - 1].back(), v[temp1 - 1].size() - 1, temp1);
            gotoXY(31, 33); b_color(to_string(1), 78);
            temp1 = 1;
            continue;
        }
        v = chuyen(temp1, temp2, v);
        DrawBox(190, 30, 20, 20 + (temp1 - 1) * 25, 12, 0);
        temp1 = temp2;
        luot++;
        gotoXY(10, 4); cout << "NICE MOVE!   ";
        bang_batdau(0, temp1);
    }
}