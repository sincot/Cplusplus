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

	// ʵ������ += ���� --- ��������� += 
	// ����ֵ������Ȼ��Data������
	// ���øú����Ķ���ĳ�Ա�������ı���
	/*
	Data& operator+=(int day)
	{
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

		//����+=��Ľ����Ҳ����*this
		// *this���˵�ǰ���������*this��Ȼ���ڣ����Կ����ô����÷���
		return *this;
	}
	*/

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
	
	//���� -= ���� --- ��������� -=
	// ����ֵ������Ȼ��Data������
	// ���øú����Ķ���ĳ�Ա�������ı���
	//Data& operator-=(int day)
	//{
	//	m_day -= day;

	//	while (m_day <= 0)
	//	{
	//		m_month--;
	//		
	//		// monthΪ0����ʼ���������
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
	
	/*
	//���� - ���غ���
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
	

	/*
	//δ���� -= ����
	Data& operator-(int day)
	{
		// Ϊ�˱�����øú����Ķ���ĳ�Ա�����ᱻ�ı�
		// ��ָ����øú����Ķ����ָ��this����һ��
		Data tmp(*this); //�����˿������캯��

		//��tmp������ԭ����thisָ��
		tmp.m_day -= day;

		//��λ
		while (tmp.m_day <= GetMonthDay(tmp.m_year, tmp.m_month))
		{
			tmp.m_month--;

			// monthΪ0����ʼ���������
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
	// ��ֵ���������
	// data1 = data3 --- data1�ĵ�ַ������thisָ�룬rdata3��data3�ı���
	void operator=(const Data& rdata3)
	{
		m_year = rdata3.m_year;
		m_month = rdata3.m_month;
		m_day = rdata3.m_day;
	}
	*/

	// ��ֵ���������
	// data1 = data3 --- data1�ĵ�ַ������thisָ�룬rdata3��data3�ı���
	// data1 = data3�ķ���ֵ��data1
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
	//data1 = data3; // ��ֵ����

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