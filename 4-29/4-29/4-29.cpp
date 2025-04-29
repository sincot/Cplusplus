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


	Data& operator++() // ++data1
	{
		//对象本身需要改变 --- 调用了+=重载函数
		*this += 1;

		//由于返回值出作用域后仍然存在，所以可以用传引用返回
		return *this;
	}

	Data operator++(int) // data1++
	{
		//对象本身不需要改变 --- 调用了+=重载函数
		Data tmp(*this);
		*this += 1;

		//由于返回值出作用域后被析构，所以不可以用传引用返回
		return tmp;
	}

	Data& operator--()  // --data1
	{
		//对象本身需要改变 --- 调用了-=重载函数
		*this -= 1;
		//由于返回值出作用域后仍然存在，所以可以用传引用返回
		return *this;
	}

	Data operator--(int)  // data1--
	{
		//对象本身不需要改变 --- 调用了-=重载函数
		Data tmp(*this);
		*this -= 1;

		//由于返回值出作用域后被析构，所以不可以用传引用返回
		return tmp;
	}

	//重载 == --- data1 == data2
	bool operator==(const Data& rdata)
	{
		return m_year == rdata.m_year
			&& m_month == rdata.m_month
			&& m_day == rdata.m_day;
	}

	//重载 != --- data1 != data2
	bool operator!=(const Data& rdata)
	{
		return !(*this == rdata);
	}

	//重载 < --- data1 < data2
	bool operator<(const Data& rdata)
	{
		//先将那些返回true的条件都实现了
		//剩下的条件就是返回false的了，可以直接返回false

		//年小就小
		if (m_year < rdata.m_year)
		{
			return true;
		}
        //年相等，月小就小
		else if (m_year == rdata.m_year && m_month < rdata.m_month)
		{
			return true;
		}
		//年相等，月相等，天小就小
		else if (m_year == rdata.m_year && m_month == rdata.m_month
			&& m_day < rdata.m_day)
		{
			return true;
		}

		//都不小，就返回false
		return false;
	}

	//重载 <= --- data1 <= data2
	bool operator<=(const Data& rdata)
	{
		//调用 < 重载函数 与 == 重载函数
		return *this < rdata || *this == rdata;
	}

	//重载 > --- data1 > data2
	bool operator>(const Data& rdata)
	{
		//调用 <= 重载函数，然后取反不就是 > 了吗？
		return !(*this <= rdata);
	}

	//重载 >= --- data1 >= data2
	bool operator>=(const Data& rdata)
	{
		//调用 < 重载函数，然后取反不就是 >= 了吗？
		return !(*this < rdata);
	}

	//日期 - 日期
	// data1 - data2
	int operator-(Data& rdata)
	{
		//一开始并不知道哪个日期大，哪个日期小
		//可以先假设，若不正确再调整
		Data max = *this; // 假设日期对象data1大
		Data min = rdata; // 假设日期对象data2大

		//调整
		if (*this < rdata)
		{
			max = rdata;
			min = *this;
		}

		//让小的日期往大的日期方向去加，加了几次就相差多少天
		int count = 0; // 计数器
		while (min != max)
		{
			++count;
			++min;
		}

		return count;
	}

private:
	int m_year;
	int m_month;
	int m_day;
};

int main()
{
	/*Data data1(2025, 4, 29);
	data1.DataPrint();
	Data data2 = ++data1;
	data1.DataPrint();
	data2.DataPrint();*/

	/*Data data1(2025, 4, 29);
	data1.DataPrint();
	Data data2 = data1++;
	data1.DataPrint();
	data2.DataPrint();*/

	/*Data data1(2025, 4, 29);
	data1.DataPrint();
	Data data2 = --data1;
	data1.DataPrint();
	data2.DataPrint();*/

	/*Data data1(2025, 4, 29);
	data1.DataPrint();
	Data data2 = data1--;
	data1.DataPrint();
	data2.DataPrint();*/

	/*
	Data data1(2025, 4, 29);
	data1.DataPrint();
	Data data2 = data1.operator++(); //前置++
	data1.DataPrint();
	data2.DataPrint();

	Data data3(2028, 6, 28);
	data3.DataPrint();
	//后置++或后置--的显式重载函数的括号里面可以传任意int类型的值
	Data data4 = data3.operator++(100); //后置++
	data3.DataPrint();
	data4.DataPrint();
	*/

	Data data1(2025, 4, 29);
	Data data2(2027, 6, 10);
	std::cout << (data1 - data2) << std::endl;

	/*std::cout << (data1 > data2) << std::endl;
	std::cout << (data1 >= data2) << std::endl;
	std::cout << (data2 > data1) << std::endl;
	std::cout << (data2 >= data1) << std::endl;
	std::cout << (data1 < data2) << std::endl;
	std::cout << (data1 <= data2) << std::endl;
	std::cout << (data2 < data1) << std::endl;
	std::cout << (data2 <= data1) << std::endl;
	std::cout << (data1 == data2) << std::endl;
	std::cout << (data1 != data2) << std::endl;
	std::cout << (data1 == data1) << std::endl;
	std::cout << (data2 != data2) << std::endl;*/

	return 0;
}