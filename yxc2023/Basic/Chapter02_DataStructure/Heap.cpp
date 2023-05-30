#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int h[N], ph[N], hp[N], size, k;

void heap_swap(int a, int b)
{
	swap(ph[hp[a]], ph[hp[b]]);
	swap(hp[a], hp[b]);
	swap(h[a], h[b]);
}
void down(int f)
{
	int maxi = f; // 父节点的下标
	if (f * 2 <= size && h[f * 2] > h[f]) // 若左节点存在且值比父节点大
		maxi = f * 2;
	if (f * 2 + 1 <= size && h[f * 2 + 1] > h[f]) // 若右节点存在且值比父节点大
		maxi = f * 2 + 1;
	if (maxi != f) // 如果执行了if,则max会被改变,说明要交换
	{
		// swap(h[f], h[maxi]);
		heap_swap(f, maxi); // 交换后,max的位置就是下一层根节点 
		down(maxi); // 递归地向下调整
	}
}

void up(int c)
{
	while (c / 2 && h[c] > h[c / 2]) // 父节点存在且子节点值更大
	{
		// swap(h[c], h[c / 2]);
		heap_swap(c, c / 2);
		c >>= 1; // 向上迭代
	}
}
void insert(int x)
{
	size++;k++;
	ph[k] = size, hp[size] = k;
	h[size] = x;
	up(size);
}
int getMax()
{
	return h[1];
}
void removeMax()
{
	heap_swap(1, size);
	size--;
	down(1);
}
void remove(int k, int x)
{
	int idx = ph[k];
	heap_swap(idx, size);
	size--;
	down(k), up(k);
}
void change(int k, int x)
{
	int idx = ph[k];
	h[idx] = x;
	down(k), up(k);
}
void print()
{
	for (int i = 1; i <= size; i++) printf("%d ", h[i]);
		printf("\n");
}
int main()
{
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	print();

	return 0;
}