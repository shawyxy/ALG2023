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
	if(L == R) return;
	int i = L - 1, j = R + 1, mid = (L + R) >> 1;
	int x = arr[mid];
	while(i < j)
	{
		do i++; while(arr[i] < x);
		do j--; while(arr[j] > x);

		if(i < j) swap(arr[i], arr[j]);
	}
	QuitSortTest(arr, L, j), QuitSortTest(arr, j + 1, R);
}
// 整数二分
// 目的：根据某种规则，使得数组的元素分为两部分，目的是找到分界点


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
		//QuitSortTest(arr, 0, SIZE - 1);
        Print(arr);
    }
}
int main()
{	
	Test();
	return 0;
}