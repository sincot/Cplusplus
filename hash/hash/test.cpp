#include "hashtable.h"

void test1()
{
    const size_t N = 1000000;
    unordered_set<int> us;
    set<int> s;
    vector<int> v;
    v.reserve(N);
    srand(time(0));
    // 将随机数存储到vector容器中
    for (size_t i = 0; i < N; ++i)
    {
        //v.push_back(rand()); // N比较大时，重复值比较多
        v.push_back(rand() + i); // 重复值相对少
        //v.push_back(i); // 没有重复，有序
    }

    size_t begin1 = clock();
    for (auto e : v)
    {
        s.insert(e);
    }
    size_t end1 = clock();
    cout << "set insert:" << end1 - begin1 << endl;

    size_t begin2 = clock();
    us.reserve(N);
    for (auto e : v)
    {
        us.insert(e);
    }
    size_t end2 = clock();
    cout << "unordered_set insert:" << end2 - begin2 << endl;
    cout << endl;

    int m1 = 0;
    size_t begin3 = clock();
    for (auto e : v)
    {
        auto ret = s.find(e);
        if (ret != s.end())
        {
            ++m1;
        }
    }
    size_t end3 = clock();
    cout << "set find:" << end3 - begin3 << "->" << m1 << endl;

    int m2 = 0;
    size_t begin4 = clock();
    for (auto e : v)
    {
        auto ret = us.find(e);
        if (ret != us.end())
        {
            ++m2;
        }
    }
    size_t end4 = clock();
    cout << "unorered_set find:" << end4 - begin4 << "->" << m2 << endl;
    cout << endl;

    cout << "插入数据个数：" << s.size() << endl;
    cout << "插入数据个数：" << us.size() << endl << endl;

    size_t begin5 = clock();
    for (auto e : v)
    {
        s.erase(e);
    }
    size_t end5 = clock();
    cout << "set erase:" << end5 - begin5 << endl;
    size_t begin6 = clock();

    for (auto e : v)
    {
        us.erase(e);
    }
    size_t end6 = clock();
    cout << "unordered_set erase:" << end6 - begin6 << endl << endl;
}

void test2()
{
    const size_t N = 1000000;
    unordered_map<int, int> um;
    map<int, int> m;
    vector<int> v;
    v.reserve(N);
    srand(time(0));
    // 将随机数存储到vector容器中
    for (size_t i = 0; i < N; ++i)
    {
        //v.push_back(rand()); // N⽐较⼤时，重复值⽐较多
        v.push_back(rand() + i); // 重复值相对少
        //v.push_back(i); // 没有重复，有序
    }

    size_t begin1 = clock();
    for (auto e : v)
    {
        m.insert({e, e});
    }
    size_t end1 = clock();
    cout << "map insert:" << end1 - begin1 << endl;

    size_t begin2 = clock();
    um.reserve(N);
    for (auto e : v)
    {
        um.insert({e,e});
    }
    size_t end2 = clock();
    cout << "unordered_map insert:" << end2 - begin2 << endl;
    cout << endl;

    int m1 = 0;
    size_t begin3 = clock();
    for (auto& e : v)
    {
        auto ret = m.find(e);
        if (ret != m.end())
        {
            ++m1;
        }
    }
    size_t end3 = clock();
    cout << "map find:" << end3 - begin3 << "->" << m1 << endl;

    int m2 = 0;
    size_t begin4 = clock();
    for (auto& e : v)
    {
        auto ret = um.find(e);
        if (ret != um.end())
        {
            ++m2;
        }
    }
    size_t end4 = clock();
    cout << "unorered_map find:" << end4 - begin4 << "->" << m2 << endl;
    cout << endl;

    cout << "插入数据个数：" << m.size() << endl;
    cout << "插入数据个数：" << um.size() << endl << endl;

    size_t begin5 = clock();
    for (auto e : v)
    {
        m.erase(e);
    }
    size_t end5 = clock();
    cout << "set erase:" << end5 - begin5 << endl;
    size_t begin6 = clock();

    for (auto e : v)
    {
        um.erase(e);
    }
    size_t end6 = clock();
    cout << "unordered_set erase:" << end6 - begin6 << endl << endl;
}

namespace HashBucket
{
    void test()
    {
        HashBucket<int, int> hb;
        int arr[] = { 19, 30, 5, 36, 13, 20, 21, 12, 14 };
        for (auto e : arr)
        {
            hb.Insert({ e, e });
        }
    }
}

int main()
{
    //test1();
    //test2();
    HashBucket::test();

    /*for (size_t i = 0; i < 100; i++)
    {
        hb.Insert({ i, i });
    }*/

    /*for (auto e : arr)
    {
        ht.Insert({ e, e });
    }*/
	return 0;
}