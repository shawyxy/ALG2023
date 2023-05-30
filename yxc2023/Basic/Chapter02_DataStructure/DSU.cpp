#include <iostream>
using namespace std;

const int N = 100010;
int f[N], size[N];
// int find(int x)
// {
// 	if(f[x] == x) return x;
// 	else return find(f[x]);	
// }

// 路径压缩
int find(int x)
{
	if(f[x] == x) return f[x] = x;
	return find(f[x]);
}

memset(size, 1, sizeof(size));
void unionset(int x, int y)
{
	x = find(x), y = find(y);
	if (x == y) return;
	if (size[x] > size[y]) swap(x, y);
	f[x] = y;
	size[y] += size[x];
}

int main()
{
	return 0;
}