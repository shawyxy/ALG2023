#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int N = 100010;
int s[N], a[N];

// 一维前缀和 
// 公式:s[i] = s[i - 1] + a[i]
// 下标从1开始,默认a[0] == s[0] == 0
// input:
// 5
// 1 2 3 4 5
// output:
// 1 3 6 10 15
void sum1(int n)
{
	for(int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
}
void sum1Test()
{
	int n = 0;
	cin >> n;
	for(int i = 1; i <= n; i++)
		a[i] = i;
	sum1(n);
	for(int i = 1; i <= n; i++) cout << s[i] << " ";
	cout << endl;
}

// 一维差分
// 已知An, 构造一个Sn,那么An就是Sn的差分,是前缀和的逆运算
// 要求,求出S[L, R]+c的结果
// 算法1:暴力-O(N)
// 算法2:差分-O(1)
// 对于A1, A2, A3, A4, ... , An
// 将A[L]+c,那么对于Sn来说,L~N项都要加上这个A[L]
// 所以S[L~N]+c,对于S[R+1, N]多加了c
// 那么将A[R+1]-c,对于S[R+1, N]就和多加的抵消了
// input
// 5 5
// output
// 1 8 11 15 15 
void diff(int a[], int s[], int L, int R, int c)
{
	a[L] += c;
	a[R + 1] -= c;
}
void sum2Test()
{
	int n = 0, c = 0;
	cin >> n >> c;
	for(int i = 1; i <= n; i++)
		a[i] = i;

	diff(a, s, 2, 4, c);
	sum1(n);
	
	for(int i = 1; i <= n; i++) cout << s[i] << " ";
	cout << endl;
}

int main()
{
	// sum1Test();
	sum2Test();
	return 0;
}