#include "Admin.h"
#include "UI.h"
#include "User.h"
#include "System.h"

int addUser(List<User> &listUser)
{
	while (1)
	{
		User user;
		string choose;
		int getChoose;

		system("cls");
		mainForm();
		gotoxy(37, 8);
		cout << "<ADD USER>";
		gotoxy(17, 11);
		cout << "MENU";
		gotoxy(12, 13);
		cout << "<1> Add acedemic staff";
		gotoxy(12, 14);
		cout << "<2> Add lecturer";
		gotoxy(12, 15);
		cout << "<3> Back";
		gotoxy(12, 16);
		cout << "<4> Logout";
		gotoxy(12, 17);
		cout << "<5> Exit";
		gotoxy(4, 20);
		cout << "Choose function: ";
		while (1)
		{
			char ch = _getch();
			if (ch == '\r')
				if (choose.size() == 0)
					continue;
				else
					break;
			else
			{
				if (ch == '\b')
					if (choose.size() == 0)
						continue;
					else
					{
						gotoxy(21, 20);
						cout << " ";
						gotoxy(21, 20);
						choose.erase(0, 1);
					}
				else
				{
					if (choose.size() != 0 || (ch != '1' && ch != '2' && ch != '3'
						&& ch != '4' && ch != '5'))
						continue;
					else
					{
						cout << ch;
						choose += ch;
					}
				}
			}
		}
		getChoose = stoi(choose);
		
		switch (getChoose)
		{
		case 1:
		case 2:
			if (addUserInfo(user, listUser) == false)
			{
				Sleep(2000);
				continue;
			}
			if (getChoose == 1)
				user.type = 1;
			else
				user.type = 2;
			addTail(listUser, user);
			gotoxy(25, 19);
			textcolor(10);
			cout << "Add completed!";
			textcolor(15);
			Sleep(2000);
			break;
		case 3:
			return -1;
		case 4:
			return logoutUI();
		case 5:
			return exitUI();
		}
	}
}
bool addUserInfo(User &user, List<User> listUser)
{
	string pass1 = "", pass2 = "";

	system("cls");
	mainForm();
	// show menu
	gotoxy(37, 8);
	cout << "<ADD USER>";
	gotoxy(18, 10);
	cout << "User information:";
	gotoxy(15, 12);
	cout << "Username: ";
	gotoxy(15, 13);
	cout << "Password: ";
	gotoxy(12, 14);
	cout << "Retype password: ";
	gotoxy(14, 15);
	cout << "Full name: ";
	gotoxy(17, 16);
	cout << "Email: ";
	gotoxy(13, 17);
	cout << "Mobile phone: ";

	// Start to input
	gotoxy(32, 12);
	getline(cin, user.username);
	gotoxy(32, 13);
	while (1)
	{
		char ch = _getch();
		if (ch != '\r')
		{
			if (ch == '\b')
			{
				if (pass1.size() == 0)
					continue;
				if (pass1.size() <= 18)
				{
					gotoxy(32 + pass1.size() - 1, 13);
					cout << " ";
					gotoxy(32 + pass1.size() - 1, 13);
				}
				pass1.erase(pass1.size() - 1, 1);
			}
			else
			{
				if (pass1.size() < 18)
					cout << "*";
				pass1 += ch;
			}
		}
		else if (pass1.size() == 0)
			continue;
		else
			break;
	}
	gotoxy(32, 14);
	while (1)
	{
		char ch = _getch();
		if (ch != '\r')
		{
			if (ch == '\b')
			{
				if (pass2.size() == 0)
					continue;
				if (pass2.size() <= 18)
				{
					gotoxy(32 + pass2.size() - 1, 14);
					cout << " ";
					gotoxy(32 + pass2.size() - 1, 14);
				}
				pass2.erase(pass2.size() - 1, 1);
			}
			else
			{
				if (pass2.size() < 18)
					cout << "*";
				pass2 += ch;
			}
		}
		else if (pass2.size() == 0)
			continue;
		else
			break;
	}
	gotoxy(32, 15);
	getline(cin, user.fullName);
	gotoxy(32, 16);
	getline(cin, user.email);
	gotoxy(32, 17);
	getline(cin, user.mobilePhone);

	// check info
	if (isExistedUser(user.username, listUser))
	{
		gotoxy(25, 18);
		textcolor(12);
		cout << "Add fail. User is existed!";
		textcolor(15);
		return false;
	}
	else if (pass1 != pass2)
	{
		gotoxy(25, 19);
		textcolor(12);
		cout << "Add fail. Password not match!";
		textcolor(15);
		return false;
	}
	else
	{
		user.password = sha256(pass1);
		return true;
	}
}