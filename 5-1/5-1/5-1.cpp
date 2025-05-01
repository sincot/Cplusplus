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

	//const成员函数
	void DataPrint() const
	{
		std::cout << m_year << "/" << m_month
			<< "/" << m_day << std::endl;
	}

	bool is_leap_year(int year)
	{
		return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
	}

	// 写一个获取当前月有几天的函数
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
	Data operator+(int day)
	{
		Data tmp(*this);

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

	//取地址运算符重载
	Data* operator&()
	{
		return (Data*)0x0012ff40;
		//return this;
		// return nullptr;
	}
	const Data* operator&() const
	{
		return (Data*)0x0012ff50;
		//return this;
		// return nullptr;
	}

	//友元函数
	friend std::ostream& operator<<(std::ostream& rout, const Data& rdata);
	friend std::istream& operator>>(std::istream& rin, Data& rdata);

private:
	int m_year;
	int m_month;
	int m_day;
};

//全局函数
//重载流提取操作符 --- cin >> data
std::istream& operator>>(std::istream& rin, Data& rdata)
{
	while (1)
	{
		std::cout << "请输入年月日： ";

		rin >> rdata.m_year >> rdata.m_month >> rdata.m_day;

		if (rdata.m_month < 1 || rdata.m_month > 12 || rdata.m_day < 1
			|| rdata.m_day > rdata.GetMonthDay(rdata.m_year, rdata.m_month))
		{
			std::cout << "输入的日期为非法日期，请重新输入" << std::endl;
		}
		else
		{
			break;
		}
	}
	
	return rin;
}


//全局函数
//重载流插入运算符 --- cout << data
std::ostream& operator<<(std::ostream& rout, const Data& rdata)
{
	rout << rdata.m_year << "年" << rdata.m_month << "月"
		<< rdata.m_day << "日" << std::endl;

	return rout;
}

int main()
{
	const Data data1(2025, 5, 1);
	data1.DataPrint();

	/*Data data1;
	Data data2;
	std::cin >> data1 >> data2;
	std::cout << data1 << data2 << std::endl;*/

	return 0;
}