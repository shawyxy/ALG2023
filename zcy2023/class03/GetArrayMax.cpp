#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int func(vector<int>& arr, int L, int R)
{
	// 只有一个元素
	if(L == R)
		return arr[L];

	int mid = L + (R - L) / 2;
	return max(func(arr, L, mid), func(arr, mid + 1, R));
}

int main()
{
	vector<int> arr = { 3, 5, 2, 3, 1, 9, 1, 3, 1, 2, 100 };
	cout << func(arr, 0, arr.size() - 1) << endl;
	return 0;
}