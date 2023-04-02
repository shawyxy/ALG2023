// 局部最小值问题是指在一个给定的数据集
// 无序且相邻值不等，找到一个局部最小值，
// 即一个值比它周围的所有值都要小。

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

bool isRight(vector<int> arr, int index) {
    if (arr.size() <= 1) {
        return true;
    }
    if (index == 0) {
        return arr[index] < arr[index + 1];
    }
    if (index == arr.size() - 1) {
        return arr[index] < arr[index - 1];
    }
    return arr[index] < arr[index - 1] && arr[index] < arr[index + 1];
}
vector<int> generateRandomArray(int maxSize, int maxValue) 
{
    srand((unsigned)time(NULL));
    vector<int> arr(rand() % maxSize + 1);
    arr[0] =   rand() % maxValue - rand() % maxValue;
    for (int i = 1; i < arr.size(); i++) 
    {
        do {
            arr[i] = rand() % maxValue - rand() % maxValue;
        } while (arr[i] == arr[i - 1]);
    }
    return arr;
}
// 定义何为局部最小值：
// 边界*2：
// 	arr[0] < arr[1]，0位置是局部最小；_-
// 	arr[N-1] < arr[N-2]，N-1位置是局部最小；-_
// 中间
//  arr[i-1] > arr[i] < arr[i+1]，i位置是局部最小；即 -_-
//  给定一个数组arr，已知任何两个相邻的数都不相等，找到随便一个局部最小位置返回
// 思路：
// 1. 首先处理左右两边的边界
// 2. 然后处理中间
		// a. 如果mid是这样的：_-_ 就二分
int getLessIndex(vector<int>& v) 
{
	if(v[0] < v[1] || v.size() == 1)
		return 0;
	int size = v.size() - 1;
	if(v[size - 1] < v[size])
		return size;
	int index = -1;
	int mid = 0, L = 0, R = size;
	while(L <= R && mid >= 0)
	{
		mid = (L + (R - L) / 2);
		if(mid > 0 && v[mid] > v[mid - 1])
		{
			R = mid - 1;
		}
		else if(v[mid] > v[mid + 1] && mid < size)
		{
			L = mid + 1;
		}
		else
		{
			return mid;
		}
		index = mid;
	}

	return index;
}

int main() {
    int testTime = 500000;
    int maxSize = 30;
    int maxValue = 100;
    cout << "测试开始" << endl;
    for (int i = 0; i < testTime; i++) {
        vector<int> arr = generateRandomArray(maxSize, maxValue);
        int ans = getLessIndex(arr);
        if (!isRight(arr, ans)) {
            cout << "出错了！" << endl;
            for(auto i : arr)
            {
            	cout << i << " ";
            }
            cout << endl;
            cout << arr[ans] << endl;
            break;
        }
    }
    cout << "测试结束" << endl;
}
