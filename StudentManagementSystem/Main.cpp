#include <iostream>
#include "AcedemicStaff.h"
#include "UI.h"
#include "User.h"
#include "Student.h"
#include "System.h"
using namespace std;

int main()
{
	Data data;
	// Struct Data chứa toàn bộ các list --> chỉ cần truyền vào các hàm "Data &data"

	// test chức năng hàm ko cần chạy giao diện bên dưới
	loadDatabase(data);
	loginUI(data);
	
	backupDatabse(data);
	// dau xanh
	return 0;
}
