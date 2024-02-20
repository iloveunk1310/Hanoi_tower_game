#pragma once
#ifndef _function_H_
#define _function_H_
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include<mmsystem.h>
#include <fstream>
#include<string>
#include <thread>
#pragma comment(lib,"winmm.lib")
using namespace std;
#define CONSOLE_WIDTH 1280
#define CONSOLE_HEIGHT 720
//Keyboard
#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGHT 77
#define KEY_ENTER 13
#define SPACE 32
#define KEY_ESC 27
using namespace std;
void SetColor(int color);
void set_color(int color);
void gotoXY(int x, int y);
void CreateConsoleWindow(int pWidth, int pHeight);
void FixConsoleWindow();
void resizeConsole(int width, int height);
void Ancontro();
void Hiencontro();
void b_color(string c, int k);
void line_up(int x, int y, int w);
void line_bot(int x, int y, int w);
void line_down(int x, int y, int w);
void DrawBox(int color, int width, int height, int x, int y, int delay);
void drawthanh(int muc, int vitri, int thanh, int color = 200);
void PrintText(string text, int color, int x, int y);
vector<string> ReadFile(string filename);
void DrawFromFile(string filename, int color, int x, int y);
void YesNoHighlight(int k); int AskContinueAction();
int AskContinueBox(bool may);
void draw_win();
void draw_nen();
vector<vector<int>> chuyen(int x, int y, vector<vector<int>> v);
void bang_batdau(int delay, int y = 1);
int cach_chuyen(int temp, int color);
bool win(vector<vector<int>> v, int n);
void nhapnhay(vector<vector<int>> v, int n);
void timer(int& kq, int &tg);
void bat_dau(int n, int& luot, int& kq);
void Save(string name, int n, int luot, int tg);
void bangchon(int snd);
int manhinhchinh(int &snd);
void record();
void dialog(string s);
void botplay(int n);
//void bar(int &n);
void _sound(int a_th);
void hienthichu(int x, int y);
#endif