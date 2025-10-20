#include <iostream>
#include <set>
#include <map>

using namespace std;

//template <class T1, class T2>
//struct pair
//{
//	typedef T1 first_type;
//	typedef T2 second_type;
//
//	T1 first;
//	T2 second;
//
//	// �޲εĹ��캯��
//	pair() : first(T1()), second(T2())
//	{}
//
//	// ���εĹ��캯��
//	pair(const T1& a, const T2& b) : first(a), second(b)
//	{}
//
//	// �������캯��
//	template<class U, class V>
//	pair(const pair<U, V>& pr) : first(pr.first), second(pr.second)
//	{}
//
//	template <class T1, class T2>
//	inline pair<T1, T2> make_pair(T1 x, T2 y)
//	{
//		return (pair<T1, T2>(x, y));
//	}
//};

int main()
{
	// {"map", "��ͼ"}�Ȼ������еĲ������Ƕ��������ʽ����ת��
	// mp ʹ�û����ų�ʼ��
	/*map<string, string> mp = { {"map", "��ͼ"}, {"left", "���"},
							   {"right", "�ұ�"}, {"string", "�ַ���"} };
	mp.insert({ "int", "����" });
	mp.insert({ "string", "����" });
	for (auto& [k, v] : mp)
	{
		cout << k << ":" << v << endl;
	}*/

	multimap<string, string> lmp = { {"map", "��ͼ"}, {"left", "���"},
							   {"right", "�ұ�"}, {"string", "�ַ���"} };
	lmp.insert({ "int", "����" });
	lmp.insert({ "string", "����" });
	for (auto& [k, v] : lmp)
	{
		cout << k << ":" << v << endl;
	}

	/*mp.insert(pair<string, string>("sort", "����"));
	mp.insert(make_pair("const", "��������"));*/
	//mp["long"];				// ����
	//cout << mp["long"] << endl;
	//mp["long"] = "������";  // �޸�
	//cout << mp["long"] << endl;
	//mp["short"] = "������"; // ���� + �޸�
	//cout << mp["short"] << endl;
	//cout << mp["map"] << endl; // ����

	

	//map<string, string>::iterator it = mp.begin();

	//auto it = mp.begin();
	//while (it != mp.end())
	//{
	//	//cout << it->first << ":" << it->second << endl;
	//	cout << (*it).first << ":" << (*it).second << endl;
	//	++it;
	//}

	/*for (auto& kv : mp)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;*/
	
	/*string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", 
					 "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };
	map<string, int> countMap;
	for (auto& str : arr)
	{
		countMap[str]++;
	}
	for (auto&[k, v] : countMap)
	{
		cout << k << ":" << v << endl;
	}
	cout << endl;*/


	/*set<int> s = { 4, 9, 3, 5, 7, 3, 1, 4, 6 };
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}*/

	//set<int> s = { 4, 9, 5, 7, 1, 2, 4, 6, 10 };
	//cout << "ɾ��ǰ��";
	//for (auto& e : s)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	//// ɾ��[3, 9] �����Ԫ��
	//// ʹ�� lower_bound ��������ȡ��һ�����ڵ���3λ�õĵ�����
	//auto it1 = s.lower_bound(3); 
	//// ʹ�� upper_bound ��������ȡ��һ������9λ�õĵ�����
	//// �����һ��Ԫ��Ϊ9�����ص���end
	//auto it2 = s.upper_bound(9);
	//// ɾ��
	//s.erase(it1, it2);

	//cout << "ɾ����";
	//for (auto& e : s)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	/*auto ret = s.find(4);
	if (ret != s.end())
	{
		cout << "�ҵ�Ԫ��4" << endl;
	}
	else
	{
		cout << "û���ҵ�" << endl;
	}

	if (s.count(4))
	{
		cout << "�ҵ�Ԫ��4" << endl;
	}
	else
	{
		cout << "û���ҵ�" << endl;
	}*/

	/*multiset<int> s = { 4, 9, 3, 5, 7, 3, 1, 4, 6 };
	cout << "Ԫ��4�ĸ�����" << s.count(4) << endl;
	cout << "Ԫ��2�ĸ�����" << s.count(2) << endl;*/

	/*for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << s.erase(3) << endl;
	
	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;*/

	return 0;
}