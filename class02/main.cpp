#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 不用额外变量交换两个数的值
// 异或结论
// A ^ A = 0
// A ^ 0 = A
// A = a, B = b
// a = a ^ b;(代入下面两个式子)
// b = a ^ b;->b = a ^ b ^ b->b = a
// a = a ^ b;->a = a ^ b ^ a->a = b

void Swap(int& a, int& b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

// 一个数组中有一种数出现了奇数次，
// 其他数都出现了偶数次，怎么找到并打印这种数 
// 思路
// 异或所有数字，剩下的就是奇数次数字

int EvenTimesOddTimes1(vector<int>& arr)
{	
	int eor = 0, size = arr.size();
	for(int i = 0; i < size; i++)
	{
		eor ^= arr[i];
	}
	return eor;
}
// 一个数组中有两种数出现了奇数次，
// 其他数都出现了偶数次，怎么找到并打印这种数 
// 思路
// 异或所有数字，剩下的就是两个奇数次数字
// 它们一定不同，那么肯定存在一个相同位置的比特位是不同的
// 以这个位置为标志，将所有数字分为两组分别重复问题1的步骤
// 最后
void EvenTimesOddTimes2(vector<int>& arr)
{	
	int eor = 0, size = arr.size();
	for(int i = 0; i < size; i++)
	{
		eor ^= arr[i];
	}
	// 取出最右侧的1,保存在int变量里面
	int rightOne = eor & (-eor);
	int eor1 = 0;
	for(int i = 0; i < size; i++)
	{
		if(arr[i] & rightOne != 0)
		{
			eor1 ^= arr[i];
		}
	}
	int num1 = eor1;
	int num2 = eor ^ eor1;
	cout << num1 << " " << num2 << endl;
}

int main()
{
	// Swap s;
	// int a[2] = {1, 2};
	// s.test(a[0], a[1]);
	// cout << a[0] << " " << a[1] << endl;

	// vector<int> v1{ 3, 3, 2, 3, 1, 1, 1, 3, 1, 1, 1 }; // 2
	// vector<int> v2{ 4, 3, 4, 2, 2, 2, 4, 1, 1, 1, 3, 3, 1, 1, 1, 4, 2, 2 }; // 3 2

	// cout << EvenTimesOddTimes1(v1) << endl;
	// EvenTimesOddTimes2(v2);

	return 0;
}