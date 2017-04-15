#ifndef _UI_H_
#define _UI_H_
#include <iostream>
#include "StructuredData.h"
#include <Windows.h>
#include <conio.h>
#include <string>
using namespace std;

void resizeConsole(int width, int height);
void textcolor(int x);
void gotoxy(int x, int y);
void createForm(int x, int y, int width, int height);
void mainForm();
void loginUI(Data &data);
int logoutUI();
Node<User>* loginUser(List<User> listUser);
void loginForm();
string inputPassword();
void loginError();
int exitUI();
void logo();

#endif // !_UI_H_