#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int main()
{
	/*set<int> s = { 3, 5, 2, 9, 8, 1, 3, 7, 2 };
	if (s.count(2))
	{
		cout << "2�ҵ���" << endl;
	}
	else
	{
		cout << "2δ�ҵ�" << endl;
	}
	
	if (s.count(6))
	{
		cout << "6�ҵ���" << endl;
	}
	else
	{
		cout << "6δ�ҵ�" << endl;
	}*/

	/*set<int> s = { 3, 5, 2, 9, 8, 1, 3, 7, 2 };
	auto it1 = s.find(2);
	if (it1 != s.end())
	{
		cout << "2�ҵ���" << endl;
	}
	else
	{
		cout << "2δ�ҵ�" << endl;
	}

	auto it2 = s.find(6);
	if(it2 != s.end())
	{
		cout << "6�ҵ���" << endl;
	}
	else
	{
		cout << "6δ�ҵ�" << endl;
	}*/

	/*for (auto& e : s1)
	{
		cout << e << " ";
	}
	cout << endl;

	cout << s1.erase(3) << endl;

	for (auto& e : s1)
	{
		cout << e << " ";
	}
	cout << endl;*/
	/*vector<int> v = { 3, 5, 2, 9, 8, 1, 3, 7, 2 };
	set<int> s2(v.begin(), v.end());*/

	/*set<int> s = { 3, 5, 2, 9, 8, 1, 3, 7, 2 };
	cout << "ɾ��ǰ��";
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	cout << s.erase(3) << endl;
	cout << "ɾ����";
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;*/

	/*multiset<int> s = { 4, 9, 3, 5, 7, 3, 1, 4, 6 };

	cout << "ɾ��ǰ��";
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	cout << "ɾ����" << s.erase(4) << "��ֵΪ4��Ԫ��" << endl;
	cout << "ɾ����";
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;*/

	/*multiset<int> s = { 4, 9, 3, 5, 7, 3, 1, 4, 6 };
	cout << "����ǰ��";
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	s.insert(6);
	cout << "�����";
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;*/
	
	/*multiset<int> s = { 4, 9, 3, 5, 7, 3, 1, 4, 6 };
	multiset<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;*/
	
	/*multiset<int> s = { 4, 9, 3, 5, 7, 3, 1, 4, 6 };
	cout << "Ԫ��4�ĸ�����" << s.count(4) << endl;
	cout << "Ԫ��1�ĸ�����" << s.count(1) << endl;
	cout << "Ԫ��8�ĸ�����" << s.count(8) << endl;*/

	// map
	/*map<string, string> map = { {"int", "����"}, {"short", "������"},
								{"long", "������"}, {"char", "�ַ���"} };
	auto it = map.begin();
	while (it != map.end())
	{
		cout << it->first << ":" <<it->second << endl;
		++it;
	}*/

	/*map<string, string> map = { {"int", "����"}, {"short", "������"},
								{"long", "������"}, {"char", "�ַ���"} };
	auto it = map.begin();
	while (it != map.end())
	{
		cout << (*it).first << ":" << (*it).second << endl;
		++it;
	}*/
	
	/*map<string, string> map = { {"int", "����"}, {"short", "������"},
								{"long", "������"}, {"char", "�ַ���"} };
	for (auto& kv : map)
	{
		cout << kv.first << ":" << kv.second << endl;
	}*/
	
	/*map<string, string> map = { {"int", "����"}, {"short", "������"},
								{"long", "������"}, {"char", "�ַ���"} };
	for (auto& [k, v] : map)
	{
		cout << k << ":" << v << endl;
	}*/

	/*map.insert(pair<string, string>("map", "��ͼ"));
	map.insert(make_pair("set", "����"));
	map.insert({ "insert", "����" });*/
	
	/*vector<pair<string, string>> v = { {"int", "����"}, {"short", "������"},
								{"long", "������"}, {"char", "�ַ���"} };
	map<string, string> map1(v.begin(), v.end());*/

	//map<string, string> map = { {"int", "����"}, {"short", "������"},
	//							{"long", "������"}, {"char", "�ַ���"} };

	//map["map"];					// ����
	//cout << map["map"] << endl;
	//map["map"] = "��ͼ";		// �޸�
	//cout << map["map"] << endl;
	//map["set"] = "����";		// ����+�޸�
	//cout << map["set"] << endl;
	//cout << map["int"] << endl; // ����


	/*auto it1 = map.begin();
	while (it1 != map.end())
	{
		cout << it1->first << ":" << it1->second << endl;
		++it1;
	}
	cout << endl;
	auto ret = map.find("int");
	ret->second += '2';
	auto it2 = map.begin();
	while (it2 != map.end())
	{
		cout << it2->first << ":" << it2->second << endl;
		++it2;
	}*/
	
	/*string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", 
				  "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };
	map<string, int> countMap;
	for (auto& str : arr)
	{
		map<string, int>::iterator it = countMap.find(str);
		if (it != countMap.end())
		{
			it->second++;
		}
		else
		{
			countMap.insert({ str, 1 });
		}
	}

	for (auto& [k, v] : countMap)
	{
		cout << k << ":" << v << endl;
	}*/
	
	//string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��",
	//				 "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };
	//map<string, int> countMap;
	//for (auto& str : countMap)
	//{
	//	countMap[str]++;
	//}
	//for (auto& [k, v] : countMap)
	//{
	//	cout << k << ":" << v << endl;
	//}

	//map<string, string> map = { {"int", "����"}, {"short", "������"},
	//						{"long", "������"}, {"char", "�ַ���"} };
	//cout << "�޸�ǰ��" << endl;
	//for (auto& [k, v] : map)
	//{
	//	cout << k << ":" << v << endl;
	//}
	//cout << endl;

	//cout << "�޸ĺ�" << endl;
	//for(auto& [k, v] : map)
	//{
	//	// key ֵ�����޸�
	//	//k += 'x'
	//	// value ֵ�����޸�
	//	v += '2';
	//	cout << k << ":" << v << endl;
	//}

	//auto it1 = map.begin();
	//while (it1 != map.end())
	//{
	//	cout << it1->first << ":" << it1->second << endl;
	//	++it1;
	//}
	//cout << endl;
	//auto it2 = map.begin();
	//while (it2 != map.end())
	//{
	//	// key ֵ�����޸�
	//	//it->first += 'x';
	//	// value ֵ�����޸�
	//	it2->second += '2';
	//	cout << it2->first << ":" << it2->second << endl;
	//	++it2;
	//}

	/*map<string, string> map = { {"int", "����"}, {"short", "������"},
							{"long", "������"}, {"char", "�ַ���"} };
	for (auto& [k, v] : map)
	{
		cout << k << ":" << v << endl;
	}
	cout << endl;

	auto ret = map.find("int");
	ret->second += '2';
	for (auto& [k, v] : map)
	{
		cout << k << ":" << v << endl;
	}*/

	/*vector<pair<string, string>> v = { {"int", "����"}, {"short", "������"},
									   {"long", "������"}, {"char", "�ַ���"} };*/
	
	
	multimap<string, string> map = { {"int", "����"}, {"short", "������"},
								{"long", "������"}, {"char", "�ַ���"} };
	map.insert({ "string", "���" });
	map.insert({ "string", "����" });
	for (auto& [k, v] : map)
	{
		cout << k << ":" << v << endl;
	}

	return 0;
}