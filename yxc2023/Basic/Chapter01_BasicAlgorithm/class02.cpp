#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// 大整数加法
vector<int> Add(vector<int>& A, vector<int> B)
{
	vector<int> c;
	int t = 0; // 进位
	for(int i = 0; i < A.size() || i < B.size(); i++)
	{
		if(i < A.size()) t += A[i];
		if(i < B.size()) t += B[i];
		c.push_back(t % 10);
		t /= 10;
	}
	return c;
}
// 大整数减法
vector<int> Sub(vector<int>& A, vector<int> B)
{
	vector<int> c;
	int t = 0; // 借位标志位，有0和1两种情况
	for(int i = 0; i < A.size(); i++)
	{
		if(i < B.size()) t -= B[i]; // 保证i在B的有效范围内
		c.push_back((t + 10) / 10);
		if(t < 0) t = 1;
		else t = 0;
		
	}
	while(c.size() > 1 && c.back() == 0) c.pop_back();
	return c;
}

// 大整数乘法
vector<int> Multi(vector<int>& A, int b)
{
	vector<int> c = { 0 };
	int t = 0;
	for(int i = 0; i < A.size() || t; i++)
	{
		if(i < A.size()) t += A[i] * b;
		c.push_back(t % 10);
		t /= 10;
	}
	return c;
}
// 大整数除法
vector<int> Divide(vector<int>& A, int b)
{
	vector<int> c;
	int r = 0; // 余数
	for(int i = A.size() - 1; i >= 0; i--)
	{
		r = r * 10 + A[i];
		c.push_back(r / b); // 商 注意除数不是10，而是指定的分母
		r %= b;
	}
	reverse(c.begin(), c.end());
	// 去除前导0，至少保证有一位0，例如1-1=0
	while(c.size() > 1 && c.back() == 0) c.pop_back();
	return c;
}
// 为了方便对进位处理，将整数倒着存放在数组中
int main()
{
	string a, b;
	vector<int> A,B;
	cin >> a >> b;
	// 将整数存放到数组中
	for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
	for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
	// vector<int> res = Add(A, B);
	// vector<int> res = Multi(A, atoi(b.c_str()));
	// vector<int> res = Divide(A, atoi(b.c_str()));
	vector<int> res = Sub(A, B);

	for(int i = res.size() - 1; i >=0; i--)
	{
		cout << res[i];
	}
	cout << endl;
	return 0;
}