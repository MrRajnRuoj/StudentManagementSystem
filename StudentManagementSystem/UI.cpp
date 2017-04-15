#include "UI.h"
#include "User.h"
#include "System.h"

// Hàm thay đổi kích cỡ của khung cmd.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

// Tạo khung
void createForm(int x, int y, int width, int height)
{
	for (int i = 0; i < width - 1; i++)
	{
		gotoxy(x + i + 1, y);
		cout << "_";
	}
	for (int i = 0; i < height; i++)
	{
		gotoxy(x + width, y + 1 + i);
		cout << "|";
	}
	for (int i = 0; i < width; i++)
	{
		gotoxy(x + i, y + height);
		cout << "_";
	}
	for (int i = 0; i < height; i++)
	{
		gotoxy(x, y + i + 1);
		cout << "|";
	}
}

// Cái khung ở ngoài ý :v
void mainForm()
{
	resizeConsole(800, 600);
	textcolor(15);
	createForm(1, 1, 84, 26);
	createForm(3, 2, 80, 24);

	gotoxy(30, 4);
	textcolor(14);
	cout << "STUDENT MANAGEMENT SYSTEM";
	textcolor(15);
	for (int i = 0; i < 7; i++)
	{
		gotoxy(34 + i, 5);
		cout << "_";
		gotoxy(44 + i, 5);
		cout << "_";
	}
	gotoxy(42, 5);
	cout << "*";
	gotoxy(41, 6);
	cout << "*";
	gotoxy(43, 6);
	cout << "*";
}
void loginUI(Data &data)
{
	while (1)
	{
		string choose;
		int isContinue;

		system("cls");
		mainForm();
		loginForm();
		isContinue = showMenu(loginUser(data.lUser), data);
		if (isContinue == 0) // isContinue = 1: logout --> make new loop for login.
			break;			 // isContinue = 0: exit.
	}
}
int logoutUI()
{
	string choose;

	textcolor(14);
	createForm(30, 11, 25, 5);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 23; j++)
		{
			gotoxy(31 + j, 12 + i);
			cout << " ";
		}
	gotoxy(32, 12);
	cout << "Do you want to logout?";
	gotoxy(35, 13);
	cout << "<1> Yes";
	gotoxy(45, 13);
	cout << "<2> No";
	gotoxy(32, 15);
	cout << "Your choose: ";
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
					gotoxy(45, 15);
					cout << " ";
					gotoxy(45, 15);
					choose.erase(0, 1);
				}
			else
			{
				if (choose.size() != 0 || (ch != '1' && ch != '2'))
					continue;
				else
				{
					cout << ch;
					choose += ch;
				}
			}
		}
	}
	textcolor(15);
	if (choose == "1")
	{
		system("cls");
		mainForm();
		textcolor(14);
		createForm(33, 11, 22, 3);
		gotoxy(36, 13);
		cout << "Logging out";
		for (int i = 0; i < 3; i++)
		{
			Sleep(500);
			cout << ". ";
		}
		Sleep(500);
		system("cls");
		textcolor(15);
		return 1;
	}
	else
		return -1;
}
void loginForm()
{
	createForm(27, 11, 30, 5);
	gotoxy(40, 12);
	cout << "LOGIN";
	gotoxy(28, 13);
	cout << "Username:";
	gotoxy(28, 14);
	cout << "Password:";
}
Node<User>* loginUser(List<User> listUser)
{
	string username, password;
	Node<User>* curLogin;
	while (1)
	{
		gotoxy(38, 13);
		
		getline(cin, username);
		gotoxy(38, 14);
		password = inputPassword();
		Node<User>* cur = isTruePassword(username, password, listUser);
		if (cur != NULL)
		{
			gotoxy(37, 15);
			for (int i = 0; i < 11; i++) cout << " ";
			gotoxy(34, 15);
			textcolor(10);
			cout << "Login successfully";
			textcolor(15);
			Sleep(2000);
			return cur;
		}
		else
			loginError();
	}
}
string inputPassword()
{
	string password = "";

	while (1)
	{
		char ch = _getch();
		if (ch != '\r')
		{
			if (ch == '\x1b')
				continue;
			if (ch == '\b')
			{
				if (password.size() == 0)
					continue;
				if (password.size() <= 16)
				{
					gotoxy(38 + password.size() - 1, 14);
					cout << " ";
					gotoxy(38 + password.size() - 1, 14);
				}
				password.erase(password.size() - 1, 1);
			}
			else
			{
				if (password.size() < 16)
					cout << "*";
				password += ch;
			}
		}
		else if (password.size() == 0)
			continue;
		else
			break;
	}
	return sha256(password);
}
void loginError()
{
	// clear input
	gotoxy(38, 13);
	for (int i = 0; i < 10; i++) cout << " ";
	gotoxy(38, 14);
	for (int i = 0; i < 20; i++) cout << " ";
	// hide old form
	textcolor(7);
	loginForm();
	textcolor(15);

	gotoxy(28, 14);

	//create error form
	createForm(24, 14, 36, 3);
	gotoxy(25, 15);
	for (int i = 0; i < 34; i++) cout << " ";
	gotoxy(25, 16);
	for (int i = 0; i < 34; i++) cout << " ";
	gotoxy(39, 15);
	textcolor(12);
	cout << "WARNING";
	gotoxy(26, 16);
	cout << "Username or Password is incorrect!";
	textcolor(15);
	Sleep(2000);
	//back to login form
	system("cls");
	mainForm();
	loginForm();

	gotoxy(37, 15);
	textcolor(14);
	cout << "Login again";
	textcolor(15);
}
int exitUI()
{
	string choose = "";
	system("cls");
	mainForm();
	textcolor(14);
	createForm(30, 11, 25, 5);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 23; j++)
		{
			gotoxy(31 + j, 12 + i);
			cout << " ";
		}
	gotoxy(33, 12);
	cout << "Do you want to exit?";
	gotoxy(34, 14);
	cout << "<1> Yes";
	gotoxy(46, 14);
	cout << "<2> No";
	gotoxy(32, 15);
	cout << "Your choose: ";
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
					gotoxy(45, 15);
					cout << " ";
					gotoxy(45, 15);
					choose.erase(0, 1);
				}
			else
			{
				if (choose.size() != 0 || (ch != '1' && ch != '2'))
					continue;
				else
				{
					cout << ch;
					choose += ch;
				}
			}
		}
	}
	textcolor(15);

	if (choose == "2")
		return -1;
	else
	{
		system("cls");
		mainForm();
		logo();
		return 0;
	}
}
void logo()
{
	gotoxy(13, 10);
	cout << " _  _                        ";
	gotoxy(13, 11);
	cout << "| || | __ _ __ __ ___   __ _ ";
	gotoxy(13, 12);
	cout << "| __ |/ _` |\\ V // -_) / _` |";
	gotoxy(13, 13);
	cout << "|_||_|\\__,_| \\_/ \\___| \\__,_|";
	gotoxy(34, 14);
	cout << "       _               _              _ ";
	gotoxy(34, 15);
	cout << " _ _  (_) __  ___   __| | __ _  _  _ | |";
	gotoxy(34, 16);
	cout << "| ' \\ | |/ _|/ -_) / _` |/ _` || || ||_|";
	gotoxy(34, 17);
	cout << "|_||_||_|\\__|\\___| \\__,_|\\__,_| \\_, |(_)";
	gotoxy(34, 18);
	cout << "                                |__/    ";
	gotoxy(60, 24);
	cout << "<Copyright by Group 11>";
	gotoxy(30, 25);
}