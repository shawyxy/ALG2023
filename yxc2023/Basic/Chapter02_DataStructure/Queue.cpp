#include <iostream>
using namespace std;
const int N = 100010;

int q[N], hh, tt = -1;

void push(int x)
{
	q[++tt] = x;
}
int pop()
{
	return q[hh++];
}
bool empty()
{
	return hh <= tt;
}
int main()
{
	push(1);
	push(2);
	push(3);
	push(4);
	while(empty())
	{
		printf("%d ", pop());
	}
	return 0;
}