// https://www.luogu.com.cn/problem/P3385

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m, s;
const int N = 100010, M = 2 * N;
int head[N], ver[M], edge[M], nxt[M], idx;
int dist[N];

void add(int x, int y, int z)
{
	idx++;
	ver[idx] = y;
	edge[idx] = z;
	nxt[idx] = head[x];
	head[x] = idx;
}

void BellmanFord(int s) // s是起点
{
	memset(dist, 0x3f, sizeof(dist));
	dist[s] = 0;
	bool relax; // 标记是否松弛成功
	// 进行n-1次迭代+最后一次检验是否有环
	for (int i = 1; i <= n; i++) // 枚举每条边
	{
		relax = false; // 初始化
		for (int x = 1; x <= n; x++) // 枚举每个顶点
		{
			// 距离为无穷大,说明它肯定不是x经过的最短路径
			if (dist[x] == 0x3f3f3f3f) continue; 
			// 枚举以x为起点的所有出边
			for (int i = head[x]; i != 0; i = nxt[i])
			{
				int y = ver[i], z = edge[i];
				if (dist[y] > dist[x] + z) // 松弛操作
				{
					dist[y] = dist[x] + z;
					relax = true; // 成功后标记
				}
			}
		}
		if (!relax) break; // 松弛失败,说明
	}
	// 第n轮循环松弛失败,说明有环
	if (relax == false) cout << "NO" << endl;
	else cout << "YES" << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		idx = 0, memset(head, 0, sizeof(head));
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			add (u, v, w);
			if (w >= 0) add (v, u, w);
		}
		BellmanFord(1); // 以1为起点
	}
	return 0;
}