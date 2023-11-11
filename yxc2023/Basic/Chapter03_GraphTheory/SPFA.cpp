// https://www.luogu.com.cn/problem/P3385

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m, s;
const int N = 100010, M = 2 * N;
int head[N], ver[M], edge[M], nxt[M], idx;
int dist[N], cnt[N]; // cnt数组存储各个点入队的次数
bool visited[N];
queue<int> q; // 用于存储待松弛的点


void add(int x, int y, int z)
{
	idx++;
	ver[idx] = y;
	edge[idx] = z;
	nxt[idx] = head[x];
	head[x] = idx;
}

bool spfa(int s) 
{
	memset(cnt, 0, sizeof(cnt)); 
	memset(dist, 0x3f, sizeof(dist));
	memset(visited, false, sizeof(visited));
	dist[s] = 0;
	q.push(s);visited[s] = true; // 将源点入队，并标记为已访问
	while (!q.empty()) // 当队列不为空时，循环执行
	{
		int x = q.front(); q.pop(); visited[x] = false; // 取出队首元素x，并出队，标记为未访问
		for (int i = head[x]; i != 0; i = nxt[i]) // 遍历以x为起点的所有边
		{
			int y = ver[i], z = edge[i]; // y是边的终点，z是边的权值
			if (dist[y] > dist[x] + z) // 如果可以通过x到y的边松弛y
			{
				dist[y] = dist[x] + z; // 更新y的最短距离
				if (++cnt[y] > n) return true; // 如果y入队的次数超过了n，说明存在负权环，返回true
				if (!visited[y]) // 如果y不在队列中
					q.push(y), visited[y] = true; // 将y入队，并标记为已访问
			}
		}
	}
	return false; // 如果没有发现负权环，返回false
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
		if (spfa(1) == true) puts("YES");
		else puts("NO");
	}
	return 0;
}