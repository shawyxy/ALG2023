#include <iostream>
using namespace std;
const int N = 100010;

int stk[N], tt;

void push(int x)
{
	stk[++tt] = x;
}
int pop()
{
	return stk[tt--];
}
bool empty()
{
	return tt > 0;
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