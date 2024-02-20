#include "function.h"
int cn = 0;
void _sound(int a_th) {
    if (a_th == 1) PlaySound(TEXT("live.wav"), NULL, SND_ASYNC | SND_LOOP);
    else if (a_th == 2) PlaySound(TEXT("win.wav"), NULL, SND_ASYNC);
    else PlaySound(NULL, NULL, SND_ASYNC);
}
void dialog(string s) {
    DrawBox(240, 50, 10, 35, 15, 0);
    DrawBox(20, 50, 1, 35, 15, 0);
    gotoXY(36, 15); SetColor(30);
    cout << s;
    SetColor(240);
}
string dienten(int toado, int toado2) {
    char key = 0; int t = 0;
    string s;
    gotoXY(toado,toado2);
    while (1) {
        key = _getch();
        if (key != 13 && key != 27) {
            if (key != 8 && t < 12) {
                s.push_back(key);
                t++;
                cout << key;
            }
            else if (key == 8 && t > 0) {
                s.pop_back();
                t--;
                gotoXY(toado + t, toado2);
                cout << " " << "\b";
            }
        }
        else if (key == 13) return s;
        else return "1";
    }
}
void hienthichu(int x,int y) {
    string s = "Feb 2024\nHello World,\nI am Nguyen Nhat Minh.\n M@";
    gotoXY(x, y);
    for (int i = 0; i < s.length(); i++) {
        SetColor(180);
        cout << s[i];
        Beep(500, 100);
        if (s[i] == '\n') {
            y++; gotoXY(x, y);
        }
    }
}
int manhinhchinh(int &snd) {
    Ancontro();
    system("cls");
    draw_nen();
    DrawFromFile("file_draw/bird.txt", 180, 90, 2);
    DrawFromFile("file_draw/tree.txt", 180, 1, 15);
    DrawFromFile("file_draw/bird2.txt", 180, 75, 10);
    DrawFromFile("file_draw/bird3.txt", 180, 5, 10);
    DrawFromFile("file_draw/dog.txt", 180, 6, 25);
    DrawFromFile("file_draw/hanoitower.txt", 230, 42, 3);
    char t;
    while (1) {
        bangchon(snd);
        gotoXY(45, 2 * cn + 16); cout << ">>";
        gotoXY(70, 2 * cn + 16); cout << "<<";
        t = _getch();
        if (t == 80 && cn < 6) cn++;
        else if (t == 72 && cn > 0) cn--;
        else if (t == 13) {
            if (cn != 3) break;
            else {
                 if (snd == 1) {
                    snd = 0;
                    _sound(0);
                 }
                 else {
                    snd = 1;
                    _sound(1);
                 }         
            }
        }
    }
    if (cn == 0) {
        string name;
        int n, luot = 0;
        dialog("Play game");
        Hiencontro();
        gotoXY(36, 20); cout << "Press ESC to cancel.";
        gotoXY(36, 18); cout << "Press name (max 12 characters) : "; name = dienten(69, 18);
        if (name == "1") return 1;
        gotoXY(36, 19); cout << "Choose level: "; cin >> n;
        while (n > 9 || n < 2) {
            gotoXY(48, 19); cout << "     Invalid!";
            gotoXY(36, 19); cout << " Choose level: "; cin >> n;
        }
        Ancontro();
        while (1) {
            int kq = -2, tg = 0;
            auto first = thread(bat_dau, n, ref(luot), ref(kq));
            thread second(timer, ref(kq), ref(tg));
            Sleep(5000);
            //auto third = thread(bar, ref(kq));
            first.join();
            second.join();
            //third.join();
            if (kq == 1) return 1;
            _sound(2);
            Sleep(5000);
            char key = _getch();
            if (key == 'f' || key == 'F') kq = 0;
            else kq = -1;
            if (kq == 0) {
                Save(name, n, luot, tg);
                _sound(snd);
                HANDLE hConsoleColor;
                hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsoleColor, 240);
                continue;
            }
            else if (kq == -1) {
                Save(name, n, luot, tg);
                return 1;
            }
            return 1;
        }
    }
    else if (cn == 2) {
        record();
        return 1;
    }
    else if (cn == 1) {
        dialog("Bot play");
        gotoXY(36, 18); cout << "Choose level: ";
        int n; cin >> n;
        botplay(n);
        return 1;
    }
    else if (cn == 5) {
        draw_nen();
        hienthichu(4, 10);
        gotoXY(4, 15); cout << "Press any key to continue...";
        int i = 2;
        //bar(i);
        _getch();
        return 1;
    }
    else if (cn == 6) {
        dialog("Exit");
        gotoXY(36, 18); cout << "Exit to desktop?";
        int cn = 0;
        while (1) {
            SetColor(100);
            if (cn %2==0) {
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
            if (key == 13 && cn % 2 == 0) return 0;
            if (key == 13 && cn % 2 == 1) return 1;
        }
    }
}