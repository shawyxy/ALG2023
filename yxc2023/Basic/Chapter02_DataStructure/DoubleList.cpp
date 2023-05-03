#include <iostream>
using namespace std;
const int N = 100010;

int val[N], l[N], r[N], idx;

void init()
{
	l[0] = 0, r[0] = 1;
	idx = 2;
}

void add(int pos, int x)
{
	val[idx] = x;
	r[idx] = r[pos];
	l[idx] = pos;
	l[r[pos]] = idx;
	r[pos] = idx;
}
void remove(int pos)
{
	r[l[pos]] = r[pos];
	l[r[pos] = l[pos]];
}

int main()
{
	
	return 0;
}