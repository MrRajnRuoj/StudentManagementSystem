#include "StructuredData.h"
#include "User.h"
#include "UI.h"
#include"Student.h"
#include "Admin.h"
#include "System.h"

// Function for showing menu's user
int showMenu(Node<User>* user, Data &data)
{
	int isContinue = 0; // = 1: logout, = 0: exit, = -1: back to menu
	while (1)
	{
		system("cls");
		mainForm();
		if (user->data.type == 0)
		{
			gotoxy(4, 7);
			cout << "Student: " << user->data.fullName;
			gotoxy(4, 8);
			cout << "ID: " << user->data.username;
			gotoxy(4, 9);
			cout << "Class: " << user->data.classOfSt;
			isContinue = menuStudent(user);
		}
		else if (user->data.type == 1)
		{
			gotoxy(4, 7);
			cout << "Teacher: " << user->data.fullName;
			isContinue = menuAcedemicStaff(data);
		}
		else if (user->data.type == 2)
		{
			gotoxy(4, 7);
			cout << "Lecturer: " << user->data.fullName;
			isContinue = menuLecturer(data, user);
		}
		else
		{
			gotoxy(4, 7);
			cout << "Adminstrator: " << user->data.fullName;
			isContinue = menuAdminstrator(data.lUser);
		}

		if (isContinue == 1 || isContinue == 0)
			break;
	}

	return isContinue;
}
int menuStudent(Node<User> *user)
{
	while (1)
	{
		bool checkBoss;
		string choose;
		int getChoose;

		gotoxy(17, 11);
		cout << "MENU";
		gotoxy(9, 13);
		cout << "<1> Check-in class";
		gotoxy(9, 14);
		cout << "<2> Logout";
		gotoxy(9, 15);
		cout << "<3> Exit";
		gotoxy(4, 17);
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
						gotoxy(21, 17);
						cout << " ";
						gotoxy(21, 17);
						choose.erase(0, 1);
					}
				else
				{
					if (choose.size() != 0 || (ch != '1' && ch != '2' && ch != '3'))
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
			system("cls");
			checkIN(user->data.username, user->data.classOfSt);
			gotoxy(35, 14);
			cout << "Done!";
			Sleep(1000);
			return -1;
		case 2:
			return logoutUI();
		case 3:
			return exitUI();
		}
	}
}
int menuLecturer(Data &data, Node<User> *user)
{
	while (1)
	{
		string choose;
		int getChoose;

		gotoxy(17, 11);
		cout << "MENU";
		gotoxy(9, 13);
		cout << "<1> Import scores";
		gotoxy(9, 14);
		cout << "<2> Logout";
		gotoxy(9, 15);
		cout << "<3> Exit";
		gotoxy(4, 17);
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
						gotoxy(21, 17);
						cout << " ";
						gotoxy(21, 17);
						choose.erase(0, 1);
					}
				else
				{
					if (choose.size() != 0 || (ch != '1' && ch != '2' && ch != '3'))
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
			// install Import scores function here!
		case 2:
			return logoutUI();
		case 3:
			return exitUI();
		}
	}
}
int menuAcedemicStaff(Data &data)
{
	while (1)
	{
		string choose;
		int getChoose;

		gotoxy(17, 11);
		cout << "MENU";
		gotoxy(9, 13);
		cout << "<1> Import courses";
		gotoxy(9, 14);
		cout << "<2> Import student lists";
		gotoxy(9, 15);
		cout << "<3> Import schedules";
		gotoxy(9, 16);
		cout << "<4> Export scores of student or courses";
		gotoxy(9, 17);
		cout << "<5> Export lists of student who was present or absent in class";
		gotoxy(9, 18);
		cout << "<6> Logout";
		gotoxy(9, 19);
		cout << "<7> Exit";
		gotoxy(4, 21);
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
						gotoxy(21, 21);
						cout << " ";
						gotoxy(21, 21);
						choose.erase(0, 1);
					}
				else
				{
					if (choose.size() != 0 || (ch != '1' && ch != '2' && ch != '3' && ch != '4' && ch != '5' && ch != '6' && ch != '7'))
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
			// install Import courses function here!
			break;
		case 2:
			// install Import student lists here!
			break;
		case 3:
			// install Import schedules here!
			break;
		case 4:
			// install Export	scores of student or course here!
			break;
		case 5:
			// Export	lists of student who was present or	absent in class here!
			break;
		case 6:
			return logoutUI();
		case 7:
			return exitUI();
		}
	}
}
int menuAdminstrator(List<User> &listUser)
{
	int isContinue = 0;
	while (1)
	{
		string choose;
		int getChoose;

		gotoxy(17, 11);
		cout << "MENU";
		gotoxy(12, 13);
		cout << "<1> Add user";
		gotoxy(12, 14);
		cout << "<2> Logout";
		gotoxy(12, 15);
		cout << "<3> Exit";
		gotoxy(4, 17);
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
						gotoxy(21, 17);
						cout << " ";
						gotoxy(21, 17);
						choose.erase(0, 1);
					}
				else
				{
					if (choose.size() != 0 || (ch != '1' && ch != '2' && ch != '3'))
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
			return addUser(listUser);
		case 2:
			return logoutUI();
		case 3:
			return exitUI();
		}
		if (isContinue == 1)
			break;
	}
	return isContinue;
}

// Function for login
bool isExistedUser(string username, List<User> listUser)
{
	Node<User>* cur = listUser.pHead;
	if (username == "")
		return false;
	while (cur != NULL)
	{
		if (username == cur->data.username)
			return true;
		cur = cur->pNext;
	}
	return false;
}
Node<User>* isTruePassword(string username, string password, List<User> listUser)
{
	Node<User>* cur = listUser.pHead;

	while (cur != NULL)
	{
		if (username == cur->data.username && password == cur->data.password)
			return cur;
		cur = cur->pNext;
	}
	return NULL;
}

// Function for modifying user information
int modifyUserInfo(Node<User> *user)
{
	User newInfo;

	system("cls");
	mainForm();
	gotoxy(32, 9);
	cout << "PERSONAL INFORMATION";
	gotoxy(15, 11);
	cout << "Username         :";
	gotoxy(34, 11);
	textcolor(7);
	cout << user->data.username;
	textcolor(15);
	gotoxy(15, 12);
	cout << "Full name        :";
	gotoxy(34, 12);
	textcolor(7);
	cout << user->data.fullName;
	textcolor(15);
	gotoxy(15, 13);
	cout << "New password     :";
	gotoxy(15, 14);
	cout << "Retype password  :";
	gotoxy(15, 15);
	cout << "Email            : ";
	cout << user->data.email;
	gotoxy(15, 16);
	cout << "Mobile phone     : ";
	cout << user->data.mobilePhone;
	changePassword(newInfo.password);
	while (1)
	{
		if (newInfo.email.size() == 0)
		{
			gotoxy(34, 15);
			cout << user->data.email;
			gotoxy(60, 15);
			textcolor(7);
			cout << "(Press ESC to skip)";
			textcolor(15);
			gotoxy(34, 15);
		}
		else if (newInfo.email.size() == 1)
		{
			gotoxy(35, 15);
			for (int i = 0; i < user->data.email.size(); i++) cout << " ";
			gotoxy(60, 15);
			for (int i = 0; i < 20; i++) cout << " ";
			gotoxy(35, 15);
		}
		char ch = _getch();
		if (ch != '\r')
		{
			if (ch == '\x1b')
				if (newInfo.email.size() == 0)
				{
					gotoxy(60, 15);
					for (int i = 0; i < 20; i++) cout << " ";
					break;
				}
				else
					continue;
			if (ch == '\b')
			{
				if (newInfo.email.size() == 0)
					continue;
				if (newInfo.email.size() <= 20)
				{
					gotoxy(34 + newInfo.email.size() - 1, 15);
					cout << " ";
					gotoxy(34 + newInfo.email.size() - 1, 15);
				}
				newInfo.email.erase(newInfo.email.size() - 1, 1);
			}
			else
			{
				if (newInfo.email.size() < 20)
					cout << ch;
				newInfo.email += ch;
			}
		}
		else if (newInfo.email.size() == 0)
			continue;
		else
			break;
	}
	while (1)
	{
		if (newInfo.mobilePhone.size() == 0)
		{
			gotoxy(34, 16);
			cout << user->data.mobilePhone;
			gotoxy(60, 16);
			textcolor(7);
			cout << "(Press ESC to skip)";
			textcolor(15);
			gotoxy(34, 16);
		}
		else if (newInfo.mobilePhone.size() == 1)
		{
			gotoxy(35, 16);
			for (int i = 0; i < user->data.mobilePhone.size(); i++) cout << " ";
			gotoxy(60, 16);
			for (int i = 0; i < 20; i++) cout << " ";
			gotoxy(35, 16);
		}
		char ch = _getch();
		if (ch != '\r')
		{
			if (ch == '\x1b')
				if (newInfo.mobilePhone.size() == 0)
				{
					gotoxy(60, 16);
					for (int i = 0; i < 20; i++) cout << " ";
					break;
				}
				else
					continue;
			if (ch == '\b')
			{
				if (newInfo.mobilePhone.size() == 0)
					continue;
				if (newInfo.mobilePhone.size() <= 20)
				{
					gotoxy(34 + newInfo.mobilePhone.size() - 1, 16);
					cout << " ";
					gotoxy(34 + newInfo.mobilePhone.size() - 1, 16);
				}
				newInfo.mobilePhone.erase(newInfo.mobilePhone.size() - 1, 1);
			}
			else
			{
				if (newInfo.mobilePhone.size() < 20)
					cout << ch;
				newInfo.mobilePhone += ch;
			}
		}
		else if (newInfo.mobilePhone.size() == 0)
			continue;
		else
			break;
	}

	if (isCompleted())
	{
		if (newInfo.password.size() != 0)
			user->data.password = newInfo.password;
		if (newInfo.email.size() != 0)
			user->data.email = newInfo.email;
		if (newInfo.mobilePhone.size() != 0)
			user->data.mobilePhone = newInfo.mobilePhone;
	}

	// remove completed form
	for (int i = 0; i <= 5; i++)
		for (int j = 0; j <= 25; j++)
		{
			gotoxy(31 + j, 17 + i);
			cout << " ";
		}
	gotoxy(34, 18);
	textcolor(10);
	cout << "Information Updated!";
	textcolor(15);
	Sleep(1000);

	return -1;
}
bool changePassword(string &password)
{
retry:
	string pass1 = "", pass2 = "";

	while (1)
	{
		if (pass1.size() == 0)
		{
			gotoxy(60, 13);
			textcolor(7);
			cout << "(Press ESC to skip)";
			textcolor(15);
			gotoxy(34, 13);
		}
		else if (pass1.size() == 1)
		{
			gotoxy(60, 13);
			for (int i = 0; i < 20; i++) cout << " ";
			gotoxy(34 + pass1.size(), 13);
		}
		char ch = _getch();
		if (ch != '\r')
		{
			if (ch == '\x1b')
				if (pass1.size() == 0)
				{
					gotoxy(60, 13);
					for (int i = 0; i < 20; i++) cout << " ";
					return false;
				}
				else
					continue;
			if (ch == '\b')
			{
				if (pass1.size() == 0)
					continue;
				if (pass1.size() <= 16)
				{
					gotoxy(34 + pass1.size() - 1, 13);
					cout << " ";
					gotoxy(34 + pass1.size() - 1, 13);
				}
				pass1.erase(pass1.size() - 1, 1);
			}
			else
			{
				if (pass1.size() < 16)
					cout << "*";
				pass1 += ch;
			}
		}
		else if (pass1.size() == 0)
			continue;
		else
			break;
	}
	gotoxy(34, 14);
	while (1)
	{
		char ch = _getch();
		if (ch != '\r')
		{
			if (ch == '\x1b')
				continue;
			if (ch == '\b')
			{
				if (pass2.size() == 0)
					continue;
				if (pass2.size() <= 16)
				{
					gotoxy(34 + pass2.size() - 1, 14);
					cout << " ";
					gotoxy(34 + pass2.size() - 1, 14);
				}
				pass2.erase(pass2.size() - 1, 1);
			}
			else
			{
				if (pass2.size() < 16)
					cout << "*";
				pass2 += ch;
			}
		}
		else if (pass2.size() == 0)
			continue;
		else
			break;
	}
	if (pass1 == pass2)
	{
		password = sha256(pass1);
		return true;
	}

	// else
	gotoxy(60, 14);
	textcolor(12);
	cout << "Password not match!";
	textcolor(15);
	Sleep(1000);
	gotoxy(60, 14);
	for (int i = 0; i < 20; i++) cout << " ";
	gotoxy(34, 13);
	for (int i = 0; i < pass1.size(); i++) cout << " ";
	gotoxy(34, 14);
	for (int i = 0; i < pass2.size(); i++) cout << " ";
	goto retry;
	return false;
}
bool isCompleted()
{
	string choose;

	createForm(31, 17, 25, 5);
	//for (int i = 0; i < 3; i++)
	//	for (int j = 0; j < 23; j++)
	//	{
	//		gotoxy(32 + j, 19 + i);
	//		cout << " ";
	//	}
	gotoxy(33, 18);
	cout << "Do you want to update?";
	gotoxy(34, 20);
	cout << "<1> Yes";
	gotoxy(46, 20);
	cout << "<2> No";
	gotoxy(32, 21);
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
					gotoxy(45, 21);
					cout << " ";
					gotoxy(45, 21);
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
		return true;
	return false;
}