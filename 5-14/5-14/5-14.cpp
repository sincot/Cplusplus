#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1("hello world");  // ֱ�Ӹ��ַ���
	const string str2("hello Cpp");
	string str3("13579");
	const string str4("24680");

	/*
	//������
	// �õ���������һ������ it1��ָ���ַ��������ַ�   
	string::iterator it1 = str1.begin();
	while (it1 != str1.end())
	{
		(*it1)++;
		cout << *it1 << "\t";
		it1++;
	}
	cout << endl;
	cout << str1 << endl;

	// const ������ ���� ָ������ݲ����޸ģ���*it2�����޸�
	string::const_iterator it2 = str2.cbegin();
	while (it2 != str2.cend())
	{
		cout << *it2 << "\t";
		it2++;
	}
	cout << endl;
	cout << str2 << endl;

	//��������� ���� ���ű���
	string::reverse_iterator it3 = str3.rbegin();
	while (it3 != str3.rend())
	{
		(*it3)++;
		cout << *it3 << "\t";
		it3++;
	}
	cout << endl;
	cout << str3 << endl;

	//const ���������
	string::const_reverse_iterator it4 = str4.crbegin();
	while (it4 != str4.crend())
	{
		cout << *it4 << "\t";
		it4++;
	}
	cout << endl;
	cout << str4 << endl;
	*/

	/*
	// ��Χfor
	// �������ͨ�ĵ�������ת��Ϊ��ͨ�汾
	// �����const�ĵ�������ת��Ϊconst�汾
	for (auto ch : str1)
	{
		ch++;
		cout << ch << " ";
	}
	cout << endl;

	for (auto ch : str2)
	{
		ch++;
		cout << ch << " ";
	}
	cout << endl;

	for (auto ch : str3)
	{
		ch++;
		cout << ch << " ";
	}
	cout << endl;

	for (auto ch : str4)
	{
		ch++;
		cout << ch << " ";
	}
	cout << endl;
	*/

	/*
	//������ӿ� ���� max_size
	// ��ͬ�ı��������������һ��
	cout << str1.max_size() << endl;
	cout << str2.max_size() << endl;
	cout << str3.max_size() << endl;
	cout << str4.max_size() << endl;
	*/

	// �Ա��ַ�����size��capacity
	// size �� capacity ����Ĵ�С��������β�ַ� \0 
	/*
	cout << str1.size() << endl;
	cout << str1.capacity() << endl;
	cout << endl;

	cout << str2.size() << endl;
	cout << str2.capacity() << endl;
	cout << endl;

	cout << str3.size() << endl;
	cout << str3.capacity() << endl;
	cout << endl;

	cout << str4.size() << endl;
	cout << str4.capacity() << endl;
	cout << endl;
	*/
    
	// ���ݵķ�ʽC++ ��û�ж���׼����ͬ�ı�������׼��һ��
    // �۲���Vs�������£����ݱ�׼
	string str;
	size_t old = str.capacity(); // ��������ǰ��capacityֵ
	cout << "capacity" << old << endl;

	for (size_t i = 0; i < 100; i++)
	{
		str.push_back('c');  // β��


		if (str.capacity() != old)
		{
			old = str.capacity();
			cout << "capacity��" << old << endl;
		}
	}
	cout << endl;
	//�ɽ����֪�����˵�һ�����ݣ����������ݶ���1.5������

	/*
	//clear ���� ֻ�ǽ��ַ�����size��Ϊ0�����ַ�����������գ�
	cout << "size��" << str.size() << endl;
	cout << "capacity��" << str.capacity() << endl;
	str.clear();
	cout << "size��" << str.size() << endl;
	cout << "capacity��" << str.capacity() << endl;
	*/

	/*
    // shrink_to_fit ���� ����
	//�� str
	cout << "size��" << str.size() << endl;
	cout << "capacity��" << str.capacity() << endl;
	str.shrink_to_fit();
	cout << "size��" << str.size() << endl;
	cout << "capacity��" << str.capacity() << endl;
	cout << endl;

	// �� str3
	cout << "size��" << str3.size() << endl;
	cout << "capacity��" << str3.capacity() << endl;
	str3.shrink_to_fit();
	cout << "size��" << str3.size() << endl;
	cout << "capacity��" << str3.capacity() << endl;
	*/

	/*
	// reserve �ӿ� 
	// ��ǰ֪���Լ���Ҫ���Ŀռ䣬���ռ俪�ã��������ݣ������Ч��
	//����
	cout << "size��" << str1.size() << endl;
	cout << "capacity��" << str1.capacity() << endl;
	str1.reserve(50);
	cout << "size��" << str1.size() << endl;
	cout << "capacity��" << str1.capacity() << endl;
	cout << endl;

	//���� ���� ����ʧ�ܣ���reserve���ݲ����ף���shrink_to_fit����
	cout << "size��" << str3.size() << endl;
	cout << "capacity��" << str3.capacity() << endl;
	str3.reserve(4);
	cout << "size��" << str3.size() << endl;
	cout << "capacity��" << str3.capacity() << endl;
	cout << endl;
	*/

	/*
	// resize �ӿ�
	cout << str3 << endl;
	cout << "size��" << str3.size() << endl;
	cout << "capacity��" << str3.capacity() << endl;
	cout << endl;

	// n > capacity > size ���� �������ݣ���size���ӵ� n ��
	str3.resize(17, '*');
	cout << str3 << endl;
	cout << "size��" << str3.size() << endl;
	cout << "capacity��" << str3.capacity() << endl;
	cout << endl;
	
	// ***************************************************
	cout << str1 << endl;
	cout << "size��" << str1.size() << endl;
	cout << "capacity��" << str1.capacity() << endl;
	cout << endl;

	// capacity > n > size ���� �������ݣ���size���ӵ� n ��
	str1.resize(11, '*');
	cout << str1 << endl;
	cout << "size��" << str1.size() << endl;
	cout << "capacity��" << str1.capacity() << endl;
	cout << endl;
	
	// ***************************************************
	cout << str << endl;
	cout << "size��" << str.size() << endl;
	cout << "capacity��" << str.capacity() << endl;
	cout << endl;

	// n < size ���� ɾ�����ݣ��� size ������ n 
	str.resize(10);
	cout << str << endl;
	cout << "size��" << str.size() << endl;
	cout << "capacity��" << str.capacity() << endl;
	cout << endl;

	// ***************************************************
	cout << str << endl;
	cout << "size��" << str.size() << endl;
	cout << "capacity��" << str.capacity() << endl;
	cout << endl;

	// δ���Σ�Ĭ�ϲ������ '\0'
	str.resize(20);
	cout << str << endl;
	cout << "size��" << str.size() << endl;
	cout << "capacity��" << str.capacity() << endl;
	cout << endl;
	*/
    
    /*
	// operator[]
	str1[0]++;
	cout << str1[0] << endl;

	//�����Խ���ˣ��������ᱨ��Ϊʲô��
	//��Ϊ�������ú�������
	//�����str1[14]ʵ����ת��Ϊstr1.operator[](14)
	str1[14]++;
	cout << str1[14] << endl;

	//���������Խ���ˣ����Ǳ�����δ����Ϊʲô��
	//��Ϊ����ļ�����ñ�����������
	//������������������±�Խ����һ�ֳ����Ϊ
	int arr[10];
	arr[14] = 1;
	*/
    
    /*
    // append ���� ׷��
	str1.push_back(' '); // β��
	str1.append("and earth"); // ����׷�������е��ַ���
	cout << str1 << endl << endl;
	str1.append(30, '*');
	cout << str1 << endl << endl;
	*/
    
    /*
    // operator += 
	cout << str1 << endl << endl;
	str1 += " and earth";
	cout << str1 << endl << endl;
	str1 += ' ';
	str1 += str2;
	cout << str1 << endl << endl;
	*/
    
    /*
    // insert �ӿ�
    // insert ��Ҫ����ʹ�ã���Ϊ�ײ��漰���ݵ�Ų����Ч�ʵ���
	cout << str1 << endl << endl;
    str1.insert(0, "new ");
	cout << str1 << endl << endl;
	str1.insert(0, 1, ' ');
	str1.insert(0, 8, '*');
	cout << str1 << endl << endl;
	str1.insert(str1.begin(), '*');
	cout << str1 << endl << endl;
	*/
    
    /*
    // erase �ӿ� ���� ɾ���ַ�����
	cout << str1 << endl << endl;
    str1.erase(5, 1); //���±�Ϊ5���ַ�ɾ��
	cout << str1 << endl << endl;
	str1.erase(5);   // ���±�Ϊ5���ַ����Ժ���ַ���ɾ��
	cout << str1 << endl << endl;
	*/
    
    // replace �ӿ�
    // replace ��Ҫ����ʹ�ã���Ϊ�ײ��漰���ݵ�Ų����Ч�ʵ���
    /*
    string str5("hello   world");
	cout << str5 << endl << endl;
	str5.replace(5, 3, "$");
	cout << str5 << endl << endl;
	*/

	string str5("water graphically @ g .mail .com");
	cout << str5 << endl << endl;
	//���ַ���str5�еĿո�ȫ���滻��%%
	//�ҵ��ַ���str5�еĿո�
	
	/*
	// ���µķ���Ч���е��
	size_t pos = str5.find(' ');

	// npos Ϊ string ���еĳ�Ա����
	while (pos != string::npos)
	{
		str5.replace(pos, 1, "%%");

		// pos + 2 �Ͳ���ÿ�ζ�Ҫ��ͷ��ʼ��
		pos = str5.find(' ', pos + 2);
	}
	cout << str5 << endl << endl;
	*/

	// �Ľ�����
	string str6;
	for (auto ch : str5)
	{
		if (ch == ' ')
		{
			str6 += "%%";
		}
		else
		{
			str6 += ch;
		}
	}

	cout << str6 << endl << endl;

	return 0;
}