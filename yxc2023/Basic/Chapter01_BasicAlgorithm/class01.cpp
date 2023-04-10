#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

void Print(vector<int>& arr)
{
	for(auto& e : arr)
	{
		cout << e << " ";
	}
	cout << endl;
}
// 快排
// 基本思路
// 1. 确定分界点
// 2. 调整区间
// 3. 左右递归处理
void QuitSortTest(vector<int>& arr, int L, int R)
{
	// 终止条件
	if(L == R) return;

	// 确定x
	int mid = L + ((R - L) >> 1);
	int x = arr[mid];
	// 确定双指针
	int i = L - 1, j = R + 1;
	// 缩小指针之间范围
	while(i < j)
	{
		do i++; while(arr[i] <= x);
		do j--; while(arr[j] > x);
		if(i < j) swap(arr[i], arr[j]); // 如果 i<j，说明这两个元素是一个逆序对
	}
	// 跳出循环，此时i==j，而且后面递归不用管已经被ij扫描过的元素(画图)
	// 左右递归
	QuitSortTest(arr, L, i), QuitSortTest(arr, i + 1, R);
}
// 整数二分
// 目的：根据某种规则，使得数组的元素分为两部分，目的是找到分界点
#define X = 10;
bool check(auto& e, auto& x) // 判断元素是否比x小
{
	if(e < x) return true;
	else return false;
}
// [L, R] -> [L, mid] + [mid+1, R]
void BinarySortTest(vector<int>& arr, int L, int R)
{
	while(L < R)
	{
		int mid = (L + R) >> 1;
		if(check(arr[mid]), X) R = mid; // 如果mid元素比x小
		else L = mid + 1;
	}
	return L;
}

#define SIZE 15
#define TIMES 5

void Test()
{
	srand(time(nullptr));	
    for (int i = 0; i < TIMES; i++) 
    {
        vector<int> arr;
        arr.resize(SIZE);
        for (int j = 0; j < SIZE; j++) 
        {
            arr[j] = rand() % 201 - 100;
        }
        Print(arr);
		QuitSortTest(arr, 0, SIZE - 1);
        Print(arr);
    }
}
int main()
{	
	Test();
	return 0;
}