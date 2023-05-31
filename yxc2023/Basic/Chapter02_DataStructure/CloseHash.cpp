#include <iostream>
using namespace std;

const int N = 200010, null = 0x3f3f3f3f;

int h[N];

memset(h, sizeof(h), 3f);

int find(int x)
{
	int pos = (x % N + N) % N;
	while (h[pos] != null && h[pos] != x) // pos位置被占且这个位置不是x
	{
		pos++;	// 向后探测
		if (pos == N) N = 0; // 遇到结尾,回到开头继续探测
	}
	return pos;
}

void insert(int x)
{
	int pos = (x % N + N) % N;
	int newpos = find(pos);
	h[newpos] = x;
}
int main()
{

	return 0;
}