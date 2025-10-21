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
		cout << "2找到了" << endl;
	}
	else
	{
		cout << "2未找到" << endl;
	}
	
	if (s.count(6))
	{
		cout << "6找到了" << endl;
	}
	else
	{
		cout << "6未找到" << endl;
	}*/

	/*set<int> s = { 3, 5, 2, 9, 8, 1, 3, 7, 2 };
	auto it1 = s.find(2);
	if (it1 != s.end())
	{
		cout << "2找到了" << endl;
	}
	else
	{
		cout << "2未找到" << endl;
	}

	auto it2 = s.find(6);
	if(it2 != s.end())
	{
		cout << "6找到了" << endl;
	}
	else
	{
		cout << "6未找到" << endl;
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
	cout << "删除前：";
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	cout << s.erase(3) << endl;
	cout << "删除后：";
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;*/

	/*multiset<int> s = { 4, 9, 3, 5, 7, 3, 1, 4, 6 };

	cout << "删除前：";
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	cout << "删除了" << s.erase(4) << "个值为4的元素" << endl;
	cout << "删除后：";
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;*/

	/*multiset<int> s = { 4, 9, 3, 5, 7, 3, 1, 4, 6 };
	cout << "插入前：";
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	s.insert(6);
	cout << "插入后：";
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
	cout << "元素4的个数：" << s.count(4) << endl;
	cout << "元素1的个数：" << s.count(1) << endl;
	cout << "元素8的个数：" << s.count(8) << endl;*/

	// map
	/*map<string, string> map = { {"int", "整型"}, {"short", "短整型"},
								{"long", "长整型"}, {"char", "字符型"} };
	auto it = map.begin();
	while (it != map.end())
	{
		cout << it->first << ":" <<it->second << endl;
		++it;
	}*/

	/*map<string, string> map = { {"int", "整型"}, {"short", "短整型"},
								{"long", "长整型"}, {"char", "字符型"} };
	auto it = map.begin();
	while (it != map.end())
	{
		cout << (*it).first << ":" << (*it).second << endl;
		++it;
	}*/
	
	/*map<string, string> map = { {"int", "整型"}, {"short", "短整型"},
								{"long", "长整型"}, {"char", "字符型"} };
	for (auto& kv : map)
	{
		cout << kv.first << ":" << kv.second << endl;
	}*/
	
	/*map<string, string> map = { {"int", "整型"}, {"short", "短整型"},
								{"long", "长整型"}, {"char", "字符型"} };
	for (auto& [k, v] : map)
	{
		cout << k << ":" << v << endl;
	}*/

	/*map.insert(pair<string, string>("map", "地图"));
	map.insert(make_pair("set", "集合"));
	map.insert({ "insert", "插入" });*/
	
	/*vector<pair<string, string>> v = { {"int", "整型"}, {"short", "短整型"},
								{"long", "长整型"}, {"char", "字符型"} };
	map<string, string> map1(v.begin(), v.end());*/

	//map<string, string> map = { {"int", "整型"}, {"short", "短整型"},
	//							{"long", "长整型"}, {"char", "字符型"} };

	//map["map"];					// 插入
	//cout << map["map"] << endl;
	//map["map"] = "地图";		// 修改
	//cout << map["map"] << endl;
	//map["set"] = "集合";		// 插入+修改
	//cout << map["set"] << endl;
	//cout << map["int"] << endl; // 查找


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
	
	/*string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", 
				  "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
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
	
	//string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果",
	//				 "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
	//map<string, int> countMap;
	//for (auto& str : countMap)
	//{
	//	countMap[str]++;
	//}
	//for (auto& [k, v] : countMap)
	//{
	//	cout << k << ":" << v << endl;
	//}

	//map<string, string> map = { {"int", "整型"}, {"short", "短整型"},
	//						{"long", "长整型"}, {"char", "字符型"} };
	//cout << "修改前：" << endl;
	//for (auto& [k, v] : map)
	//{
	//	cout << k << ":" << v << endl;
	//}
	//cout << endl;

	//cout << "修改后：" << endl;
	//for(auto& [k, v] : map)
	//{
	//	// key 值不能修改
	//	//k += 'x'
	//	// value 值可以修改
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
	//	// key 值不能修改
	//	//it->first += 'x';
	//	// value 值可以修改
	//	it2->second += '2';
	//	cout << it2->first << ":" << it2->second << endl;
	//	++it2;
	//}

	/*map<string, string> map = { {"int", "整型"}, {"short", "短整型"},
							{"long", "长整型"}, {"char", "字符型"} };
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

	/*vector<pair<string, string>> v = { {"int", "整型"}, {"short", "短整型"},
									   {"long", "长整型"}, {"char", "字符型"} };*/
	
	
	multimap<string, string> map = { {"int", "整型"}, {"short", "短整型"},
								{"long", "长整型"}, {"char", "字符型"} };
	map.insert({ "string", "你好" });
	map.insert({ "string", "世界" });
	for (auto& [k, v] : map)
	{
		cout << k << ":" << v << endl;
	}

	return 0;
}