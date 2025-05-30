#include "Date.h"

int main()
{
	Date date1(2025, 5, 30);
	Date date2 = date1;
	//date1.DatePrint();
	Date date3(2026, 6, 10);
	Date date4;
	Date date5;
	cin >> date4 >> date5;
	cout << date4 << date5 << endl;

	/*date3 = --date1;
	date1.DatePrint();
	date3.DatePrint();*/

	/*date3 = ++date1;
	date1.DatePrint();
	date3.DatePrint();*/

	/*date3 = date1--;
	date1.DatePrint();
	date3.DatePrint();*/

	/*date3 = date1++;
	date1.DatePrint();
	date3.DatePrint();*/
	//cout << (date1 < date3) << endl;   // true
	//cout << (date3 < date1) << endl;   // false
	//cout << (date1 > date3) << endl;   // false
	//cout << (date3 > date1) << endl;   // true
	//cout << (date1 <= date3) << endl;  // true
	//cout << (date3 <= date1) << endl;  // false
	//cout << (date1 >= date3) << endl;  // false
	//cout << (date3 >= date1) << endl;  // true
	//cout << (date1 == date3) << endl;  // false
	//cout << (date1 == date2) << endl;  // true
	//cout << (date1 != date3) << endl;  // true
	//cout << (date1 != date2) << endl;  // false

	return 0;
}