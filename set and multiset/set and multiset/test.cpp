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
//	// 无参的构造函数
//	pair() : first(T1()), second(T2())
//	{}
//
//	// 带参的构造函数
//	pair(const T1& a, const T2& b) : first(a), second(b)
//	{}
//
//	// 拷贝构造函数
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
	// {"map", "地图"}等花括号中的参数都是多参数的隐式类型转换
	// mp 使用花括号初始化
	/*map<string, string> mp = { {"map", "地图"}, {"left", "左边"},
							   {"right", "右边"}, {"string", "字符串"} };
	mp.insert({ "int", "整型" });
	mp.insert({ "string", "西瓜" });
	for (auto& [k, v] : mp)
	{
		cout << k << ":" << v << endl;
	}*/

	multimap<string, string> lmp = { {"map", "地图"}, {"left", "左边"},
							   {"right", "右边"}, {"string", "字符串"} };
	lmp.insert({ "int", "整型" });
	lmp.insert({ "string", "西瓜" });
	for (auto& [k, v] : lmp)
	{
		cout << k << ":" << v << endl;
	}

	/*mp.insert(pair<string, string>("sort", "排序"));
	mp.insert(make_pair("const", "常量属性"));*/
	//mp["long"];				// 插入
	//cout << mp["long"] << endl;
	//mp["long"] = "长整型";  // 修改
	//cout << mp["long"] << endl;
	//mp["short"] = "短整型"; // 插入 + 修改
	//cout << mp["short"] << endl;
	//cout << mp["map"] << endl; // 查找

	

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
	
	/*string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", 
					 "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
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
	//cout << "删除前：";
	//for (auto& e : s)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	//// 删除[3, 9] 区间的元素
	//// 使用 lower_bound 函数，获取第一个大于等于3位置的迭代器
	//auto it1 = s.lower_bound(3); 
	//// 使用 upper_bound 函数，获取第一个大于9位置的迭代器
	//// 若最后一个元素为9，返回的是end
	//auto it2 = s.upper_bound(9);
	//// 删除
	//s.erase(it1, it2);

	//cout << "删除后：";
	//for (auto& e : s)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	/*auto ret = s.find(4);
	if (ret != s.end())
	{
		cout << "找到元素4" << endl;
	}
	else
	{
		cout << "没有找到" << endl;
	}

	if (s.count(4))
	{
		cout << "找到元素4" << endl;
	}
	else
	{
		cout << "没有找到" << endl;
	}*/

	/*multiset<int> s = { 4, 9, 3, 5, 7, 3, 1, 4, 6 };
	cout << "元素4的个数：" << s.count(4) << endl;
	cout << "元素2的个数：" << s.count(2) << endl;*/

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