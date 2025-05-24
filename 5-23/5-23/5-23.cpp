#include <iostream>
#include <vector>

using namespace std;

void func1()
{
	/*
	// ���� vector �� Vs �е����ݷ�ʽ
	vector<int> v1;
	// ����ԭ����capacity�Ĵ�С
	size_t old = v1.capacity();
	cout << "capacity = " << old << endl;
	for (size_t i = 0; i < 100; i++)
	{
		v1.push_back(i);
		if (v1.capacity() != old)
		{
			cout << "caapcity = " << v1.capacity() << endl;
			old = v1.capacity();
		}
	}
	*/

	/*
	// ͷ��
	vector<int> v;
	v.insert(v.begin(), 2);
	// β��
	v.insert(v.end(), 3);
	// �м����
	v.insert(v.begin() + 1, 4);

	for (auto e : v)
	{
		cout << e << " ";
	}
	*/

	// vector ����ĳ�ʼ��
	// ������vector�Ĺ��캯��
	vector<int> v1({ 10, 20, 30 });

	// ��ʽ����ת��
	vector<int> v2 = { 10, 20, 30 };

}

struct A
{
	A(int a1, int a2)
		:m_a1(a1)
		, m_a2(a2)
	{}

	int m_a1;
	int m_a2;
};

void func2()
{
	// ��������
	vector<A> v1;
	A aa1(10, 10);
	v1.push_back(aa1);

	// ��������
	vector<A> v2;
	v2.push_back(A(20, 20));

	// ��ʽ����ת��
	vector<A> v3;
	v3.push_back({ 30, 30 });

	// ʹ�� emplace_back
	v2.emplace_back(aa1);
	v3.emplace_back(A(20, 20));
	// ������ A �Ĳ�����Ч�ʽϸ�
	v3.emplace_back(30, 30);

	// ����
	vector<A>::iterator it2 = v2.begin();
	while (it2 != v2.end())
	{
		cout << it2->m_a1 << " " << it2->m_a2 << "\t";
		it2++;
	}
	cout << endl << endl;

	// ��Χ for
	for (auto& e : v3)
	{
		cout << e.m_a1 << " " << e.m_a2 << "\t";
	}
	cout << endl << endl;

	//�ṹ����
	for (auto& [x, y] : v1)
	{
		cout << x << " " << y << "\t";
	}
}

int main()
{
	/*
	// �޲ι���
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	// ���ι��� ���� �� 10��1 ����ʼ�� v2
	vector<int> v2(10, 1);

	// ����������
	vector<int> v3(v1.begin(), v1.end());

	// ���ֱ�����ʽ
	// 1. �±�� [ ] 
	for (size_t i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	cout << endl << endl;

	// 2. ��Χ for
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl << endl;

	// 3. ������
	vector<int>::iterator vit2 = v2.begin();
	while (vit2 != v2.end())
	{
		cout << *vit2 << " ";
		vit2++;
	}
	*/

	//func1();
	func2();

	return 0;
}