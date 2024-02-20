#include "function.h"
void record() {
	DrawBox(240, 100, 25, 20, 8, 0);
	DrawBox(20, 100, 8, 20, 8, 0);
	DrawFromFile("record.txt", 100, 47, 10);
	SetColor(240);
	fstream kiluc("kiluc.txt", ios::in);
	for (int i = 2; i < 10; i++) {
		int a, b, c; kiluc >> a >> b >> c;
		string s; getline(kiluc, s);
		gotoXY(45, 17 + i); cout << "LEVEL " << i << ": ";
		if (a != 0) {
			cout << b << " moves by:" << s << "; in: " << c / 60 << " min " << c % 60 << " sec";
		}
	}
	_getch();
	return;
}