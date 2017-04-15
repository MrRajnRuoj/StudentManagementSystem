#include <iostream>
#include "AcedemicStaff.h"
#include "UI.h"
#include "User.h"
#include "Student.h"
#include "System.h"
using namespace std;

void test()
{
	//test1
	//test2
	//test3
	//test4
}
int main()
{
	Data data;
	// Struct Data chứa toàn bộ các list --> chỉ cần truyền vào các hàm "Data &data"

	// test chức năng hàm ko cần chạy giao diện bên dưới
	loadDatabase(data);
	loginUI(data);
	
	backupDatabse(data);
	// abcxyz
	return 0;
}
