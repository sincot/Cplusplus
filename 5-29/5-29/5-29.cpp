#include "Date.h"

int main()
{
	Date date1(2027, 6, 10);
	Date date2(2025, 5, 29);
	Date date3(2027, 4, 29);
	cout << date3 << endl;
	Date date4;
	Date date5;
	cin >> date4 >> date5;
	cout << date4 << date5;

	/*Date date3 = date1++;
	date1.DatePrint();*/
	/*Date date3 = ++date1;
	date1.DatePrint();*/
	/*Date date3 = date1--;
	date1.DatePrint();*/
	/*Date date3 = --date1;
	date1.DatePrint();*/

	return 0;
}