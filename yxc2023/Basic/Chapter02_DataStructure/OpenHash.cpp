#include <iostream>
using namespace std;

const int N = 100010;

int h[N], e[N], ne[N], idx;

void insert(int x)
{
	int pos = (x % N + N) % N;
	e[idx] = x;
	ne[idx] = h[pos];
	h[pos] = idx++;
}
bool find(int x)
{
	int pos = (x % N + N) % N;
	for (int i = h[pos]; i != -1; i = ne[i])
		if(e[i] == x) return true;
	return false;
}


int main()
{

	return 0;
}
