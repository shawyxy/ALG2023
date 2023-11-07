#include <iostream>
#include <queue>
using namespace std;

const int N = 100010;
int n, m;
int in[N];
vector<int> ver[N], topo;

bool TopoSort()
{
	queue<int> q;
	// 将所有入度为0的顶点入队
	for (int i = 1; i <= n; i++)
		if (in[i] == 0) q.push(i);

	while (!q.empty())
	{
		// 取出队头元素x(理论上可以取队列中任意元素)
		int x = q.front();
		q.pop();
		topo.push_back(x);
		// 将x顶点的出边(x, y)全部删除
		// 当y顶点的入度为0,则入队
		for (auto &y : ver[x])
			if (--in[y] == 0) q.push(y);
	}

	return topo.size() == n;
}

int main()
{
	// 读入顶点数n,m行数据
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		// 读取(a, b)有向边, b的入度则+1
		ver[a].push_back(b);
		in[b]++;
	}
	if (!TopoSort()) puts("-1");
	else for (auto &e : topo) printf("%d ", e);

	return 0;
}