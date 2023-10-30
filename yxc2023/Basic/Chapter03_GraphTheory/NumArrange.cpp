#include <iostream>
using namespace std;

const int N = 100010;
int path[N];
bool visited[N];
int n;

void dfs(int x)
{
    // 当填满时，打印
	if (x == n)
	{
		for (int i = 0; i < n; i++) printf("    %d", path[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++)
	{
        // 如果这个结点还没有被访问过
		if (visited[i] != true)
		{
			path[x] = i; // 记录到路径中
			visited[i] = true; // 标记它被使用过
			dfs(x + 1); // 递归下一层
			visited[i] = false; // 递归返回后才能走到这一步，回溯还原现场
		}
	}
}

int main()
{
	while (cin >> n)
	{
		dfs(0); // 注意从第 0 个元素开始
	}
	return 0;
}