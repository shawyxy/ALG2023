#include <iostream>
using namespace std;
const int N = 100010;
int q[N], hh = 0, tt = 0;
void push(int x)
{
	q[tt++] = x;
	if(tt == N) tt = 0;
}
int pop()
{
	return q[hh++];
	if(hh == N) hh = 0;
}
bool empty()
{
	return hh != tt;
}

int main()
{
	push(1);
	push(2);
	push(3);
	push(4);

	while(empty())
	{
		cout << pop() << " ";
	}
	return 0;
}