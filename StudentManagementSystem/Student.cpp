#include"Student.h"
//#include "StructuredData.h"

//string tenFileTKB(string clas){
//	if ( clas == "16CLC1")
//		return ("16CLC1timeTable.csv");
//	if (clas == "16CLC2")
//		return ("16CLC2timeTable.csv");
//	if (clas == "16CTT")
//		return ("16CTTtimeTable.csv");
//	return "xxx";
//}

string tenFileDDanh(string clas){
	if ( clas == "16CLC1")
		return ("16CLC1DDanh.csv");
	if (clas == "16CLC2")
		return ("16CLC2DDanh.csv");
	if (clas == "16CTT")
		return ("16CTTDDanh.csv");
	return "xxx";
}

void readTKB(string name,course &c, Nodex* &pHead)
{
	pHead = NULL;
	

	int n;
	string z;
	fstream file;
	
	
	file.open(name,ios::in);
	//cin.ignore();
	getline(file,z);
	file >> c.year;
	file >> c.semester;
	file >> n;
	for ( int i = 0 ; i < n ; i ++){
		//cin.ignore();
		getline(file,c.courseCode,',');
		//cin.ignore();
		getline(file,c.courseName,',');
		//cin.ignore();
		getline(file,c.lectureUserName,',');
		//cin.ignore();
		getline(file,c.startAt,',');
		//cin.ignore();
		getline(file,c.endAt,',');
		//cin.ignore();
		getline(file,c.from,',');
		//cin.ignore();
		getline(file,c.to,',');
		//cin.ignore(10,'\n');
		getNode(pHead,c);
	}

	file.close();
}

void getNode(Nodex* &pHead,course c){
	if ( pHead == NULL)
	{
		Nodex* p = new Nodex;
		p ->val = c;
		p ->pNext = NULL;
		pHead = p;
	}
	else {

		Nodex* p = new Nodex;
		p ->val = c;
		p ->pNext = pHead;
		pHead = p;
	}
}
		
void printCur(Nodex * pHead){
	Nodex* cur;
	cur = pHead;
	if ( pHead == NULL)
		cout <<" ko co gi de in:"<<endl;
	while( cur != NULL){
		cout <<cur ->val.courseCode <<endl;
		cout <<cur ->val .courseName <<endl;
		cout <<cur ->val.semester<<endl;
		cout <<cur ->val.lectureUserName << endl;
		cout << cur ->val.startAt <<endl;
		cout << cur ->val.endAt<<endl;
		cout << cur ->val.year << endl;
		cout << cur ->val.from << endl;
		cout << cur ->val .to << endl;
		cur = cur ->pNext;
	}
}
	

tm* systempTime (time_t t){
	time_t hientai = t;

	tm* ltm = localtime(&hientai);
	return ltm;
}

bool inTime(tm* t,Nodex* pHead,string cN){
	 int tiem;
	 int x1;
	 int x2;
	
	Nodex* cur = pHead;
	while((cur ->val.courseCode) != cN){
		cur = cur ->pNext;
	}
	tiem = (t ->tm_wday)*10000 + (t ->tm_hour)*100 + (t ->tm_min);
	x1 = std::stoi(cur ->val.from );
	x2 = std::stoi( cur ->val.to);
	if (x1 <= tiem && tiem <=x2)
		return true;
	else 
		return false;
}

void dDanh(string name , string ID,string ngay,string thang, string mon,bool codihoc){
	fstream file ;
	file.open(name ,ios::out|ios :: app);
	file <<ngay<<','<<thang<<endl;
	file <<mon << ','<<endl <<endl;
	if (codihoc == true )
		file <<ID<<endl;
	file.close();
}

void checkIN(string ID,string clas){
	tm* t;
	Nodex *pHead ;
	course c;
	string  cN;
	string tenFile, fileDDanh;
	bool it;
	int chon;
	
	//cout <<"nhap lop muon doc thoi khoa bieu"<<endl; //day la de test, khi chay can cung cap ID vs class;
	tenFile = tenFileTKB(clas);

	readTKB(tenFile,c ,pHead);
	Nodex* lur = pHead;
	cout <<"nhap ma mon co trong hom nay ma ban muon diem danh"<<endl;
	for (int i = 0 ; lur  != NULL ; i ++){
		cout <<i +1<<"."<<lur ->val.courseCode <<endl;
		lur = lur ->pNext;
	}

	cin >>chon;
	Nodex* cur = pHead;
	
	for ( int i = 0 ; i <chon -1 ; i++){
	cur = cur ->pNext;
	}
	cN =cur ->val.courseCode;

	//std::fflush(stdin);
	//cout <<"nhap Id"<<endl;
	//cin >> ID;
	t =systempTime(time(0));
	it = inTime(t,pHead,cN);
	fileDDanh = tenFileDDanh(clas);
	std::string ngay = std::to_string(long double (t->tm_mday));
	std::string thang = std::to_string(long double(t ->tm_mon + 1));

	dDanh(fileDDanh,ID,ngay ,thang,cN,it);

	//printCur(pHead);
}

//


void nhapTKB (string name, string clas){
	fstream file;int n;
	course c;
	file.open(name,ios::out|ios::app);
	cout <<" nhap thoi khoa bieu cho lop "<<clas<<endl;
	file << clas <<"\n";
	cout <<"nhap nam hoc"<<endl;
	cin >> c.year;
	file << c.year <<"\n";
	cout <<"nhap hoc ki "<<endl;
	cin >> c.semester ;
	file << c.semester <<"\n";
	cout <<"nhap so luong mon hoc co trong hoc ki "<<c.semester<<endl;
	cin >> n;
	file <<n<<"\n";
	for (int i = 0 ; i < n; i ++){

	cout <<"nhap ma mon hoc"<<endl;
	cin >> c.courseCode ;
	file << c.courseCode <<",";
	cout <<"nhap ten mon hoc "<<endl;
	cin >> c.courseName;
	file << c.courseName <<",";
	cout <<"nhap ten giao vien"<<endl;
	cin >> c.lectureUserName;
	file << c.lectureUserName <<",";
	cout <<"nhap thoi gian bat dau hoc khoa hoc(YYYYMMDD)"<<endl;
	cin >> c.startAt;
	file << c.startAt <<",";
	cout <<"nhap thoi gian ket thuc khoa hoc(YYYYMMDD)"<<endl;
	cin >> c.endAt;
	file << c.endAt <<",";
	cout <<"nhap thoi gian cu the bat dau mon hoc theo form"<<endl;
	cout <<"nhap thu,thoi gian bat dau mon hoc (WWHHMM)cua 1 ngay trong tuan"<<endl;
	cin >>c.from;
	file << c.from <<",";
	cout <<"nhap thu,thoi gian ket thuc mon hoc (WWHHMM) cua 1 ngay trong tuan"<<endl;
	cin >> c.to;
	file <<c.to <<",";
	file <<"\n";
	}
	cout <<"da nhap thanh cong thoi khoa biet co "<< n <<" mon cho lop " << clas<<endl;

}

string tenFileTKB(string clas){
	if ( clas == "16CLC1")
		return ("16CLC1timeTable.csv");
	if (clas == "16CLC2")
		return ("16CLC2timeTable.csv");
	if (clas == "16CTT")
		return ("16CTTtimeTable.csv");
	return "xxx";
}
	
void inputTimeTable(){
	int nclas;
	string clas;
	string filename;
	do{
		cout <<"nhap so luong lop muon nhap thoi khoa bieu ( >0 && <=3 )"<<endl;
		cin >> nclas;
	}
	while(nclas <= 0 || nclas >3);
	for ( int i = 0 ; i < nclas; i++){
	do{
	cout <<"nhap ten lop muon nhap thoi khoa bieu (16CLC1, 16CLC2, 16CTT)"<<endl;
	cin >> clas;
	}
	while(clas !="16CLC1" && clas != "16CLC2" && clas !="16CTT");
	filename = tenFileTKB(clas);
	cout <<" da nhap ten lop thanh cong "<<endl;
	if (filename != "xxx"){
	nhapTKB(filename,clas);

	}
	}
	 
}