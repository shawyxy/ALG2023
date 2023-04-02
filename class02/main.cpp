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
		if(arr[i] && rightOne != 0)
		{
			eor1 ^= arr[i];
		}
	}
	int num1 = eor1;
	int num2 = eor ^ eor1;
	cout << num1 << " " << num2 << endl;
}
// 怎么把一个int类型的数，提取出二进制中最右侧的1来
//  N   	000011100
// ~N   	111100011
// ~N+1 	111100100

//  N&(~N+1)000000100
void Print(const int num)
{
	for(int i = 31; i >= 0; i--)
	{
		cout << ((num >> i) & 1);
	}
	cout << endl;
}
void getRightOne(const int num)
{
	Print(num);
	int And = num & (~num + 1);
	Print(And);

}
// 泛化问题：
// 一个数组中有一种数出现K次，其他数都出现了M次，
// 已知1<=K<M，找到出现了K次的数
// 要求额外空间复杂度O(1)，时间复杂度O(N)

// 只有一个数出现了一次，其他数字均出现了三次，
// 输出这一个只出现一次的数。
// 思路：将相同位置的位数加起来，整体模3，剩下的就是那个数
// 3  0011
// 3  0011
// 3  0011
// 4  0100
//    0133
// %3 0100
void kmNumFindK(vector<int>& v, int k, int m)
{
	int size = v.size();
	vector<int> sum = { 0 }; // 记录每一个位置的总比特位之和
	sum.resize(32);
	for(int i = 0; i < size; i++) // 遍历数组中的每一个数
	{
		for(int j = 1; j <= 31; j++) // 累加
		{
			if(((v[i] >> j) & 1) == 1) // 比特位为1才有效
				sum[j]++; 
		}
	}
	// 对1-31比特位，每个位置的和模3，剩下的就是只出现1次的
	// 同时将剩下的那1位
	for(int i = 1; i <= 31; i++)
	{
		sum[i] %= 3;
	}
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

	getRightOne(1231312);
	getRightOne(88);
	getRightOne(1);

	return 0;
}






































