#include<iostream>
#include<fstream>
#include<string>
#include<ctime>


using namespace std;

struct course{
	string courseCode;
	string year;
	short int semester;
	string courseName;
	string lectureUserName;
	string startAt;
	string endAt;
	string from;
	string to;
};

struct timex{
	int sec;
	int min;
	int hour;
	int wday;
	int mounth;
	int year;
	int yday;
	int myear;
	int mday;
};

struct Nodex{
	course val;
	Nodex* pNext;
};


string tenFileTKB(string clas);
string tenFileDDanh(string clas);

void readTKB(string name,course &c, Nodex* &pHead);

void getNode(Nodex* &pHead,course c);

void printCur(Nodex * pHead);

tm* systempTime (time_t t);

bool inTime(tm* t,Nodex* pHead,string cN);


void dDanh(string name , string ID,string ngay,string thang, string mon,bool codihoc);
	
void checkIN(string ID, string clas);



//

void nhapTKB (string name, string clas);
string tenFileTKB(string clas);
void inputTimeTable();