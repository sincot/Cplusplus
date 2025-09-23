#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//﻿int main(int argc, char* argv[])
//{
//
//	string a = "hello world";
//
//	string b = a;
//
//	if (a.c_str() == b.c_str())
//	{
//		cout << "true" << endl;
//	}
//
//	else cout << "false" << endl;
//
//	string c = b;
//
//	c = "";
//
//	if (a.c_str() == b.c_str())
//
//	{
//
//		cout << "true" << endl;
//
//	}
//
//	else cout << "false" << endl;
//
//	a = "";
//
//	if (a.c_str() == b.c_str())
//
//	{
//
//		cout << "true" << endl;
//
//	}
//
//	else cout << "false" << endl;
//
//	return 0;
//}

//int main()
//{
//
//	string str("Hello Bit.");
//
//	str.reserve(111);
//
//	str.resize(5);
//
//	str.reserve(50);
//
//	cout << str.size() << ":" << str.capacity() << endl;
//
//	return 0;
//
//}

/*
int main()
{
	string strText = "How are you?";
	string strSeparator = " ";
	string strResult;

	int size_pos = 0;

	int size_prev_pos = 0;

	while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)
	{

		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);

		cout << strResult << " ";

		size_prev_pos = ++size_pos;

	}

	if (size_prev_pos != strText.size())
	{

		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);

		cout << strResult << " ";

	}

	cout << endl;

	return 0;
	return 0;
}
*/

/*
class Solution {
public:
    // 计算每个位置上的数字的平方和
    int TotalSs(int n)
    {
        int ret = 0;
        while (n)
        {
            int num = n % 10;
            ret += num * num;
            n /= 10;
        }

        return ret;
    }

    bool isHappy(int n) {
        // 定义快慢指针
        int slow = n;
        int fast = n;

        // 只要快慢指针相遇就跳出循环
        while (slow != fast)
        {
            // 慢指针走一步
            slow = TotalSs(slow);
            // 快指针走两步
            fast = TotalSs(TotalSs(fast));
        }

        return slow == 1;
    }
};
*/


//class Solution {
//public:
//    int maxArea(vector<int>& height) {
//        // 定义一个最大值
//        int max = 0;
//
//        for (int i = 0; i < height.size(); i++)
//        {
//            for (int j = i + 1; j < height.size(); j++)
//            {
//                if (i * j > max)
//                {
//                    max = i * j;
//                }
//            }
//        }
//
//        return max;
//    }
//};

//class Solution {
//public:
//    int maxArea(vector<int>& height) {
//        // 定义两个指针
//        int left = 0;
//        int right = height.size() - 1;
//        int max = 0;
//
//        while (left < right)
//        {
//            // 取数的最小值
//            int min = height[left] < height[right] ? height[left] : height[right];
//            int volume = min * (right - left);
//            max = volume > max ? volume : max;
//
//            if (height[left] < height[right])
//            {
//                left--;
//            }
//            else
//            {
//                right++;
//            }
//        }
//
//        return max;
//    }
//};

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0; // 计数器

        // 排序
        sort(nums.begin(), nums.end());
        // 固定最大值
        int max = nums.size() - 1;

        while (max >= 2)
        {
            // 定义前后指针
            int left = 0;
            int right = max - 1;

            while (left <= right)
            {
                if (nums[left] + nums[right] > nums[max])
                {
                    count += right - left; // 统计[left, right]区间
                    right--;
                }
                else
                {
                    left++;
                }
            }

            // 更换固定数
            max--;
        }


        return count;
    }
};

int main()
{
    vector<int> v = { 2,2,3,4 };
    Solution sol;
    cout << sol.triangleNumber(v) << endl;

    return 0;
}