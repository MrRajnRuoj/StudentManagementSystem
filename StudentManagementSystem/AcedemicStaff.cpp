#include "AcedemicStaff.h"


void output(List<User> lst)
{
	User s;
	Node<User>* p = lst.pHead;
	if (p == NULL)
	{
		cout << "No data" << endl;
	}
	else
	{
		int i = 1;
		cout << "\n\t\tFull list " << endl;
		while (p != NULL)
		{
			cout << "\n\t\tSinh vien thu: " << i << endl;
			outputStd(p);
			p = p->pNext;
			i++;
		}

		cout << endl;
	}
}

void outputStd(Node<User>* std)
{
	cout << "Ten sv: " << std->data.fullName << endl;
	cout << "ID: " << std->data.username << endl;
	cout << "Phone: " << std->data.mobilePhone << endl;

}

void readFile(ifstream &f, List<User> &l)
{
	User s;
	init(l);


	f.open("123.txt", ios_base::in);
	while (!f.eof())
	{

		getline(f, s.fullName, ',');
		getline(f, s.username, ',');
		getline(f, s.mobilePhone);

		addTail(l, s);
	}
	f.close();
	output(l);
}

void deleteStd(ifstream &f, List<User> &l)
{
	string stdID;
	readFile(f, l);

	cout << "Ban muon xoa sinh vien nao?" << endl;
	cout << "Nhap ID: ";
	getline(cin, stdID);
	Node<User>* cur = l.pHead;
	while (cur != NULL && cur->data.username != stdID)
		cur = cur->pNext;
	if (cur == NULL)
		cout << "Student not found!" << endl;
	else
		removeK(l, cur);
}

void addStudent(List<User> &l)
{
	User s;
	int n;
	cout << "Ban muon them bao nhieu sinh vien? ";
	cin >> n;
	cout << "Moi ban nhap " << n << " sinh vien" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << "\n\t\tNhap sinh vien thu " << i << endl;
		cout << "Nhap ten: ";
		cin.ignore();
		getline(cin, s.fullName);
		cout << "Nhap ID: ";
		getline(cin, s.username);
		cout << "Nhap so dien thoai: ";
		getline(cin, s.mobilePhone);

		addTail(l, s);
	}
}

void outfile(List<User> &l, string fileOut)
{
	ofstream o;
	o.open(fileOut, ios_base::out);

	User s;
	Node<User>* p = l.pHead;
	int i = 1;
	while (p != NULL)
	{
		o << "\n\t\tSinh vien thu " << i << endl;
		o << "Ten sinh vien: " << p->data.fullName << endl;
		o << "ID: " << p->data.username << endl;
		o << "So dien thoai: " << p->data.mobilePhone << endl;
		p = p->pNext;
		i++;
	}
	o.close();
}