#include <iostream>

class Data
{
public:
	//������Ĺ��캯��
	Data(int year = 1, int month = 1, int day = 1)
	{
		m_year = year;
		m_month = month;
		m_day = day;
	}

	//const��Ա����
	void DataPrint() const
	{
		std::cout << m_year << "/" << m_month
			<< "/" << m_day << std::endl;
	}

	bool is_leap_year(int year)
	{
		return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
	}

	// дһ����ȡ��ǰ���м���ĺ���
	inline int GetMonthDay(int year, int month)
	{
		//ÿ�ζ��ǵ���̬��ȥ��
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
		//�������dayΪ��ֵ�����
		if (day < 0)
		{
			return *this -= -day;
		}

		m_day += day;

		//��λ
		while (m_day > GetMonthDay(m_year, m_month))
		{
			// ����
			m_day -= GetMonthDay(m_year, m_month);
			m_month++;

			//�·ݴﵽ13���£���ݾͿ��Խ�1�ˣ��·ݱ�Ϊ1
			if (m_month == 13)
			{
				m_month = 1;
				m_year++;
			}
		}

		return *this;
	}


	// ʵ������ + ���� --- ��������� + 
	Data operator+(int day)
	{
		Data tmp(*this);

		//��tmp������ԭ����thisָ��
		tmp.m_day += day;

		//��λ
		while (tmp.m_day > GetMonthDay(tmp.m_year, tmp.m_month))
		{
			tmp.m_day -= GetMonthDay(tmp.m_year, tmp.m_month);
			tmp.m_month++;

			//�·ݴﵽ13���£���ݾͿ��Խ�1��
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
		//�������dayΪ��ֵ�����
		if (day < 0)
		{
			return *this += -day;
		}

		m_day -= day;

		while (m_day <= 0)
		{
			m_month--;

			// monthΪ0����ʼ���������
			if (m_month == 0)
			{
				m_month = 12;
				m_year--;
			}

			m_day += GetMonthDay(m_year, m_month);
		}

		return *this;
	}

	//���� - ���� --- ��������� - 
	Data& operator-(int day)
	{
		Data tmp(*this);
		tmp -= day;

		return tmp;
	}


	Data& operator++() // ++data1
	{
		//��������Ҫ�ı� --- ������+=���غ���
		*this += 1;

		//���ڷ���ֵ�����������Ȼ���ڣ����Կ����ô����÷���
		return *this;
	}

	Data operator++(int) // data1++
	{
		//��������Ҫ�ı� --- ������+=���غ���
		Data tmp(*this);
		*this += 1;

		//���ڷ���ֵ������������������Բ������ô����÷���
		return tmp;
	}

	Data& operator--()  // --data1
	{
		//��������Ҫ�ı� --- ������-=���غ���
		*this -= 1;
		//���ڷ���ֵ�����������Ȼ���ڣ����Կ����ô����÷���
		return *this;
	}

	Data operator--(int)  // data1--
	{
		//��������Ҫ�ı� --- ������-=���غ���
		Data tmp(*this);
		*this -= 1;

		//���ڷ���ֵ������������������Բ������ô����÷���
		return tmp;
	}

	//���� == --- data1 == data2
	bool operator==(const Data& rdata)
	{
		return m_year == rdata.m_year
			&& m_month == rdata.m_month
			&& m_day == rdata.m_day;
	}

	//���� != --- data1 != data2
	bool operator!=(const Data& rdata)
	{
		return !(*this == rdata);
	}

	//���� < --- data1 < data2
	bool operator<(const Data& rdata)
	{
		//��С��С
		if (m_year < rdata.m_year)
		{
			return true;
		}
		//����ȣ���С��С
		else if (m_year == rdata.m_year && m_month < rdata.m_month)
		{
			return true;
		}
		//����ȣ�����ȣ���С��С
		else if (m_year == rdata.m_year && m_month == rdata.m_month
			&& m_day < rdata.m_day)
		{
			return true;
		}

		//����С���ͷ���false
		return false;
	}

	//���� <= --- data1 <= data2
	bool operator<=(const Data& rdata)
	{
		//���� < ���غ��� �� == ���غ���
		return *this < rdata || *this == rdata;
	}

	//���� > --- data1 > data2
	bool operator>(const Data& rdata)
	{
		//���� <= ���غ�����Ȼ��ȡ�������� > ����
		return !(*this <= rdata);
	}

	//���� >= --- data1 >= data2
	bool operator>=(const Data& rdata)
	{
		//���� < ���غ�����Ȼ��ȡ�������� >= ����
		return !(*this < rdata);
	}

	//���� - ����
	// data1 - data2
	int operator-(Data& rdata)
	{
		//һ��ʼ����֪���ĸ����ڴ��ĸ�����С
		//�����ȼ��裬������ȷ�ٵ���
		Data max = *this; // �������ڶ���data1��
		Data min = rdata; // �������ڶ���data2��

		//����
		if (*this < rdata)
		{
			max = rdata;
			min = *this;
		}

		//��С��������������ڷ���ȥ�ӣ����˼��ξ���������
		int count = 0; // ������
		while (min != max)
		{
			++count;
			++min;
		}

		return count;
	}

	//ȡ��ַ���������
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

	//��Ԫ����
	friend std::ostream& operator<<(std::ostream& rout, const Data& rdata);
	friend std::istream& operator>>(std::istream& rin, Data& rdata);

private:
	int m_year;
	int m_month;
	int m_day;
};

//ȫ�ֺ���
//��������ȡ������ --- cin >> data
std::istream& operator>>(std::istream& rin, Data& rdata)
{
	while (1)
	{
		std::cout << "�����������գ� ";

		rin >> rdata.m_year >> rdata.m_month >> rdata.m_day;

		if (rdata.m_month < 1 || rdata.m_month > 12 || rdata.m_day < 1
			|| rdata.m_day > rdata.GetMonthDay(rdata.m_year, rdata.m_month))
		{
			std::cout << "���������Ϊ�Ƿ����ڣ�����������" << std::endl;
		}
		else
		{
			break;
		}
	}
	
	return rin;
}


//ȫ�ֺ���
//��������������� --- cout << data
std::ostream& operator<<(std::ostream& rout, const Data& rdata)
{
	rout << rdata.m_year << "��" << rdata.m_month << "��"
		<< rdata.m_day << "��" << std::endl;

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