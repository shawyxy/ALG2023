#include <iostream>
using namespace std;
const int N = 100010;
int val[N], ne[N];		
int idx, head;

void init()
{
	head = -1;
	idx = 0;
}
void add_to_head(int x)
{
	val[idx] = x;		// 插入新结点的值
	ne[idx] = head;		// 更新新结点的next指针
	head = idx;			// 更新头结点的next指针
	idx++;
}
void add(int pos, int x)
{
	val[idx] = x;
	ne[idx] = ne[pos];
	ne[pos] = idx;
	idx++;
}
void remove(int pos)
{
	ne[pos] = ne[ne[pos]];
}
int main()
{
	init();
	// add_to_head(1);
	// add_to_head(2);
	// add_to_head(3);
	// add_to_head(4);
	for(int i = head; i != -1; i = ne[i])
		cout << val[i] << " ";
	return 0;
}