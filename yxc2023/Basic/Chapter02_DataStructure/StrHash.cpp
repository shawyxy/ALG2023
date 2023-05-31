#include <iostream>
using namespace std;

typedef unsigned long long ULL;
const int P = 131, N = 100010;
ULL p[N], h[N], s[N];
int n;

// 预处理 哈希值前缀和
void init()
{
	p[0] = 1, h[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		p[i] = p[i - 1] * P;
		h[i] = h[i - 1] * P + s[i];
	}
}
// 子串s[l, r]的哈希值
ULL get(int l, int r)
{
	return h[r] - h[l - 1] * p[r - l + 1];
}
