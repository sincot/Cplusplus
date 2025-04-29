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

	void DataPrint()
	{
		std::cout << m_year << "/" << m_month
			<< "/" << m_day << std::endl;
	}

	bool is_leap_year(int year)
	{
		return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
	}

	// дһ����ȡ��ǰ���м���ĺ���
	// ����year���жϵ�ǰ������Ƿ���ƽ����
	// ����month���жϵ�ǰ���·��Ǽ���
	// �Ѹú������óɾ�̬�ģ�����ÿ�ε��ö�Ҫ��������ջ֡
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
	// ����ֵ������Ȼ��Data������
	// ���øú����Ķ���ĳ�Ա�������ᱻ�ı�
	Data operator+(int day)
	{
		// Ϊ�˱�����øú����Ķ���ĳ�Ա�����ᱻ�ı�
		// ��ָ����øú����Ķ����ָ��this����һ��
		Data tmp(*this); //�����˿������캯��

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

		//����+��Ľ��������ԭ����thisָ��ָ��Ķ����еĳ�Ա������û�б��ı�
		// �����������tmp�ͱ������ˣ����Բ���ʹ�ô����÷��أ�ֻ��ʹ�ô�ֵ����
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
	// ����ֵ������Ȼ��Data������
	// ���øú����Ķ���ĳ�Ա�������ᱻ�ı�
	//������ -= ����
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
		//�Ƚ���Щ����true��������ʵ����
		//ʣ�µ��������Ƿ���false���ˣ�����ֱ�ӷ���false

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
	Data data2 = data1.operator++(); //ǰ��++
	data1.DataPrint();
	data2.DataPrint();

	Data data3(2028, 6, 28);
	data3.DataPrint();
	//����++�����--����ʽ���غ���������������Դ�����int���͵�ֵ
	Data data4 = data3.operator++(100); //����++
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