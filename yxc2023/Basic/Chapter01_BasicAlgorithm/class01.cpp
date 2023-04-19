#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

#define SIZE 15 // 测试数组长度
#define TIMES 5 // 测试数组次数
template<class T>
void Print(vector<T>& arr)
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
	if(L >= R) return;

	// 确定x
	int mid = L + ((R - L) >> 1);
	int x = arr[mid];
	// 确定双指针
	int i = L - 1, j = R + 1;
	// 缩小指针之间范围
	while(i < j)
	{
		do i++; while(arr[i] < x);
		do j--; while(arr[j] > x);
		if(i < j) swap(arr[i], arr[j]); // 如果 i<j，说明这两个元素是一个逆序对
	}
	// 跳出循环，此时i==j，而且后面递归不用管已经被ij扫描过的元素(画图)
	// 左右递归
	QuitSortTest(arr, L, j), QuitSortTest(arr, j + 1, R); // 注意j而不是i
}
// 归并排序
void MergeSort(vector<int>& arr, int L, int R)
{
	if(L == R) return;
	// 排序
	int mid = L + ((R - L) >> 1); // [error]
	MergeSort(arr, L, mid), MergeSort(arr, mid + 1, R);
	// 现在左右两边各自有序
	// 合并
	int k = 0;// 辅助数组的下标，表示现在已经合并了k个数ma
	int i = L, j = mid + 1; // ij指针分别指向mid两边区域的起始位置
	vector<int> tmp; // 定义一个辅助数组，用来存放合并后的元素
	tmp.resize(100010);
	while(i <= mid && j <= R) // ij指针不超过两个区域的右边界
	{
		if(arr[i] < arr[j]) // 把小的放在辅助数组里  
		{
			tmp[k++] = arr[i++];
		}
		else
		{
			tmp[k++] = arr[j++];
		}
	}
	// 处理可能剩下的元素
	// if(i <= mid) tmp[k++] = arr[i++]; // [error]
	// if(j <= R) tmp[k++] = arr[j++]; // error
	while(i <= mid) tmp[k++] = arr[i++]; 
	while(j <= R) tmp[k++] = arr[j++]; 


	for(i = L, j = 0; i <= R; i++, j++) arr[i] = tmp[j];
}
// 整数二分
// 输入格式
// 第一行包含整数n和q，表示数组长度和询问个数。
// 第二行包含n个整数（均在1~10000范围内），表示完整数组。
// 接下来q行，每行包含一个整数k，表示一个询问元素。
// 输出格式
// 共q行，每行包含两个整数，表示所求元素的起始位置和终止位置。
// 如果数组中不存在该元素，则返回“-1 -1”。
// 输入样例：
// 6 3
// 1 2 2 3 3 4
// 3
// 4
// 5
// 输出样例：
// 3 4
// 5 5
// -1 -1
// 思路：根据规则，使得数组的元素分为3部分，找到中间那部分的两个边界
// 对于这道题目，前提是数据是升序的，i指针找左边最远的地方，j指针找右边最远的地方
// 满足的条件是：arr[i] <= x <= arr[j]，注意，ij所在位置的下标是我们要求的
// 那么问题转化为：i找<=x的第一个元素，j找>=x的最后一个元素
int BinarySearch1(vector<int>& arr, int L, int R, int x)
{
	while(L < R)
	{
		int mid = L + ((R - L + 1) >> 1); // 当只有2个数，L和R相隔1单位，但是int除2向下取整，mid恒等于L，对于此处赋值语句，L 恒等于 L
		// int mid = (L + R + 1) / 2;
		if(arr[mid] <= x) L = mid; // 数组中间都比x小，说明数组前半部分都比x小，要找的数字肯定在mid及其右边
		else R = mid - 1;
	}
	// L == R，跳出循环
	return L;
}
int BinarySearch2(vector<int>& arr, int L, int R, int x)
{
	while(L < R)
	{
		int mid = L + ((R - L)>> 1);
		// int mid = (L + R + 1) / 2;
		if(arr[mid] >= x) R = mid;
		else L = mid + 1; 
	}
	return L;
}
// 浮点数二分
// 思路类似，由于是double，因此没有向下取整，不用考虑mid分子+1修正
double BinarySearch3(vector<double>& arr, int L, int R, double x)
{
	while(R - L > 1e-6)
	{
		double mid = (L + R) / 2;
		if(arr[mid] <=x ) L = mid;
		else R = mid - 1;
	}
	return L;
}
double BinarySearch4(vector<double>& arr, int L, int R, double x)
{
	while(R - L > 1e-6)
	{
		double mid = (L + R) / 2;
		if(arr[mid] >= x ) R = mid;
		else L = mid - 1;
	}
	return L;
}
void Test()
{
	srand(time(nullptr));	
    for (int i = 0; i < 1; i++) 
    {
        vector<int> arr;
        arr.resize(SIZE);
        for (int j = 0; j < SIZE; j++) 
        {
            arr[j] = rand() % 201 - 100;
        }
        // vector<int> arr1 = {1,1,1,1,1, 2, 2, 2, 3, 4, 5,5,5,5,5,5,5,5};
        // Print(arr1);
		//QuitSortTest(arr, 0, SIZE - 1);
		// int index1 = BinarySearch1(arr1, 0, arr1.size(), 5);
		// int index2 = BinarySearch2(arr1, 0, arr1.size(), 5);

		//MergeSort(arr, 0, SIZE - 1);
        // Print(arr1);
        // cout << index2 << " " << index1 << endl;
        vector<double> arr2 = {1.1,2.3,2.3,2.3,5.3,5.3,5.3};
        Print(arr2);
		double index3 = BinarySearch3(arr2, 0, arr2.size(), 2.3);
		double index4 = BinarySearch4(arr2, 0, arr2.size(), 2.3);
        cout << index3 << " " << index4 << endl;

    }
}
int main()
{	
	Test();
	return 0;
}