#include <iostream>

class Data
{
public:
	//日期类的构造函数
	Data(int year = 1, int month = 1, int day = 1)
	{
		m_year = year;
		m_month = month;
		m_day = day;
	}

	void DataPrint()
	{
		std::cout << m_year << "/" << m_month
			<< "/" << m_day << std::endl;
	}
    
	bool is_leap_year(int year)
	{
		return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
	}

	// 写一个获取当前月有几天的函数
	// 参数year来判断当前的年份是否是平闰年
	// 参数month来判断当前的月份是几月
	// 把该函数设置成静态的，避免每次调用都要建立函数栈帧
	inline int GetMonthDay(int year, int month)
	{
		//每次都是到静态区去找
		static int arr[13] = { -1, 31, 28, 31, 30, 31, 30, 
			            31, 31, 30, 31, 30, 31 };
		if (month == 2 && is_leap_year(year))
		{
			return 29;
		}

		return arr[month];
	}

	// 实现日期 += 天数 --- 重载运算符 += 
	// 返回值类型仍然是Data类类型
	// 调用该函数的对象的成员变量被改变了
	/*
	Data& operator+=(int day)
	{
		m_day += day;

		//进位
		while (m_day > GetMonthDay(m_year, m_month))
		{
			// 减掉
			m_day -= GetMonthDay(m_year, m_month);
			m_month++;
			
			//月份达到13个月，年份就可以进1了，月份变为1
			if (m_month == 13)
			{
				m_month = 1;
				m_year++;
			}
		}

		//返回+=后的结果，也就是*this
		// *this出了当前的作用域后，*this仍然存在，所以可以用传引用返回
		return *this;
	}
	*/

	Data& operator+=(int day)
	{
		//处理参数day为负值的情况
		if (day < 0)
		{
			return *this -= -day;
		}

		m_day += day;

		//进位
		while (m_day > GetMonthDay(m_year, m_month))
		{
			// 减掉
			m_day -= GetMonthDay(m_year, m_month);
			m_month++;

			//月份达到13个月，年份就可以进1了，月份变为1
			if (m_month == 13)
			{
				m_month = 1;
				m_year++;
			}
		}

		return *this;
	}


	// 实现日期 + 天数 --- 重载运算符 + 
	// 返回值类型仍然是Data类类型
	// 调用该函数的对象的成员变量不会被改变
	Data operator+(int day)
	{
		// 为了避免调用该函数的对象的成员变量会被改变
		// 将指向调用该函数的对象的指针this拷贝一份
		Data tmp(*this); //调用了拷贝构造函数
		
		//用tmp来代替原来的this指针
		tmp.m_day += day;

		//进位
		while (tmp.m_day > GetMonthDay(tmp.m_year, tmp.m_month))
		{
			tmp.m_day -= GetMonthDay(tmp.m_year, tmp.m_month);
			tmp.m_month++;

			//月份达到13个月，年份就可以进1了
			if (tmp.m_month == 13)
			{
				tmp.m_month = 1;
				tmp.m_year++;
			}
		}

		//返回+后的结果，但是原来的this指针指向的对象中的成员变量并没有被改变
		// 出了作用域后，tmp就被析构了，所以不能使用传引用返回，只能使用传值返回
		return tmp;
	}
	
	//日期 -= 天数 --- 重载运算符 -=
	// 返回值类型仍然是Data类类型
	// 调用该函数的对象的成员变量被改变了
	//Data& operator-=(int day)
	//{
	//	m_day -= day;

	//	while (m_day <= 0)
	//	{
	//		m_month--;
	//		
	//		// month为0，开始向年借月了
	//		if (m_month == 0)
	//		{
	//			m_month = 12;
	//			m_year--;
	//		}

	//		m_day += GetMonthDay(m_year, m_month);
	//	}

	//	return *this;
	//}

	Data& operator-=(int day)
	{
		//处理参数day为负值的情况
		if (day < 0)
		{
			return *this += -day;
		}

		m_day -= day;

		while (m_day <= 0)
		{
			m_month--;

			// month为0，开始向年借月了
			if (m_month == 0)
			{
				m_month = 12;
				m_year--;
			}

			m_day += GetMonthDay(m_year, m_month);
		}

		return *this;
	}
	
	/*
	//调用 - 重载函数
	Data& operator-=(int day)
	{
		*this = *this - day;
		
		return *this;
	}
	*/

	/*Data& operator-=(int day)
	{
		return *this - day;
	}*/

	//日期 - 天数 --- 重载运算符 - 
	// 返回值类型仍然是Data类类型
	// 调用该函数的对象的成员变量不会被改变
	//调用了 -= 函数
	Data& operator-(int day)
	{
		Data tmp(*this);
		tmp -= day;

		return tmp;
	}
	

	/*
	//未调用 -= 函数
	Data& operator-(int day)
	{
		// 为了避免调用该函数的对象的成员变量会被改变
		// 将指向调用该函数的对象的指针this拷贝一份
		Data tmp(*this); //调用了拷贝构造函数

		//用tmp来代替原来的this指针
		tmp.m_day -= day;

		//进位
		while (tmp.m_day <= GetMonthDay(tmp.m_year, tmp.m_month))
		{
			tmp.m_month--;

			// month为0，开始向年借月了
			if (tmp.m_month == 0)
			{
				tmp.m_month = 12;
				tmp.m_year--;
			}

			tmp.m_day += GetMonthDay(tmp.m_year, tmp.m_month);
		}

		return tmp;
	}
	*/

	/*
	// 赋值重载运算符
	// data1 = data3 --- data1的地址传给了this指针，rdata3是data3的别名
	void operator=(const Data& rdata3)
	{
		m_year = rdata3.m_year;
		m_month = rdata3.m_month;
		m_day = rdata3.m_day;
	}
	*/

	// 赋值重载运算符
	// data1 = data3 --- data1的地址传给了this指针，rdata3是data3的别名
	// data1 = data3的返回值是data1
	/*
	Data& operator=(const Data& rdata3)
	{
		if (this != &rdata3)
		{
			m_year = rdata3.m_year;
			m_month = rdata3.m_month;
			m_day = rdata3.m_day;
		}
		
		return *this;
	}
	*/

private:
	int m_year;
	int m_month;
	int m_day;
};

int main()
{
	Data data1(2025, 4, 28);
	data1.DataPrint();
	data1 += -100;
	data1.DataPrint();

	/*Data data1(2025, 4, 28);
	data1.DataPrint();
	Data data2 = data1 - 100000;
	data1.DataPrint();
	data2.DataPrint();*/


	/*Data data1(2025, 4, 28);
	data1.DataPrint();
	data1 -= 100000;
	data1.DataPrint();*/

	//Data data3(2028, 6, 28);
	//data1 = data3; // 赋值重载

	/*Data data1(2025, 4, 28);
	data1.DataPrint();
	Data data2 = data1 + 100;
	data1.DataPrint();
	data2.DataPrint();*/

	/*data1.DataPrint();
	Data data2(data1 += 100);
	data1.DataPrint();*/

	return 0;
}