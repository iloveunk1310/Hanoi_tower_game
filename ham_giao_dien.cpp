#include "function.h"
void CreateConsoleWindow(int pWidth, int pHeight) {
    HWND consoleWindow = GetConsoleWindow();
    RECT r;
    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 240);
    GetWindowRect(consoleWindow, &r);
    MoveWindow(consoleWindow, 0, 0, pWidth, pHeight, TRUE);
}
void FixConsoleWindow() {
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void SetColor(int color)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
void gotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void set_color(int color) {
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}
void b_color(string c, int k) {
    HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleColor, k);
    std::cout << c;
    return;
}
void Ancontro() {
    CONSOLE_CURSOR_INFO Info;
    Info.bVisible = FALSE;
    Info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void Hiencontro()
{
    CONSOLE_CURSOR_INFO Info;
    Info.bVisible = TRUE;
    Info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void DrawBox(int color, int width, int height, int x, int y, int delay)
{
	SetColor(color);
	gotoXY(x, y);

	for (int i = 0; i < width; i++)
	{
		cout << " ";
	}
	for (int i = 1; i <= height; i++)
	{
		Sleep(delay);
		gotoXY(x, y + i);
		cout << " ";
		SetColor(color);
		for (int j = 0; j < width - 2; j++)
		{
			cout << " ";
		}
		cout << " ";
	}
	gotoXY(x, y + height + 1);
	Sleep(delay);
	for (int i = 0; i < width; i++)
	{
		cout << " ";
	}
	SetColor(240);
}
void PrintText(string text, int color, int x, int y)
{
	gotoXY(x, y);
	SetColor(color);
	cout << text;
	SetColor(240);
}
vector<string> ReadFile(string filename)
{
	std::fstream textFile;
	textFile.open(filename.c_str(), std::fstream::in);
	string line;
	std::vector<std::string> line1;
	while (getline(textFile, line))
		line1.push_back(line);
	textFile.close();
	return line1;
}
void DrawFromFile(string filename, int color, int x, int y)
{
	int tempY = y;
	vector<string> line1 = ReadFile(filename);

	if (filename == "XWin.txt" || filename == "OWin.txt" || filename == "Draw.txt" || filename == "PWin.txt" || filename == "PLose.txt")
	{
	}
	else
	{
		for (int i = 0; i < line1.size(); i++)
		{
			PrintText(line1[i], color, x, y);
			y++;
		}
	}
}
void line_up(int x, int y, int w) {
    for (int i = x; i <= x + w; i++) {
        gotoXY(i, y);
        printf("%c", char(196));
    }
    gotoXY(x, y); printf("%c", char(218));
    gotoXY(x + w, y); printf("%c", char(191));
    gotoXY(x, y + 1); printf("%c", char(179));
    gotoXY(x + w, y + 1); printf("%c", char(179));
}
void line_bot(int x, int y, int w) {
    for (int i = x; i <= x + w; i++) {
        gotoXY(i, y);
        printf("%c", char(196));
    }
    gotoXY(x, y); printf("%c", char(195));
    gotoXY(x + w, y); printf("%c", char(180));
    gotoXY(x, y + 1); printf("%c", char(179));
    gotoXY(x + w, y + 1); printf("%c", char(179));
}
void line_down(int x, int y, int w) {
    for (int i = x; i <= x + w; i++) {
        gotoXY(i, y);
        printf("%c", char(196));
    }
    gotoXY(x, y); printf("%c", char(192));
    gotoXY(x + w, y); printf("%c", char(217));
}
void resizeConsole(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void drawthanh(int muc, int vitri, int thanh, int color) {
    DrawBox(color, 2 + 2*muc, 0, 31 + 25 * (thanh - 1) - muc, 30 - vitri * 2, 0);
    gotoXY(31 + (thanh - 1) * 25, 31 - vitri * 2); cout << muc;
}
void draw_nen() {
    DrawBox(180, 140, 40, 0, 0, 0);
}



