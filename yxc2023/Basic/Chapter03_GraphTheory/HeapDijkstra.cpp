#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m, s;
const int N = 100010, INF = 1e9, M = 2 * N;
int dist[M];
int head[N], ver[M], edge[M], Next[M], idx;
bool visited[M];

// pair<-dist[x], x>
priority_queue<pair<int, int>> heap;
// 加边
void add(int x, int y, int z)
{
    idx++;
    ver[idx] = y;
    edge[idx] = z;
    Next[idx] = head[x];
    head[x] = idx;
}

void dijkstra(int s)
{
	// 初始化
	memset(dist, 0x3f, sizeof(dist));
	memset(visited, false, sizeof(visited));
	dist[s] = 0;
	heap.push(make_pair(0, s));
	while (!heap.empty())
	{
		int x = heap.top().second;
		if (visited[x]) continue;
		visited[x] = true;

		for (int i = head[x]; i; i = Next[i])
		{
			int y = ver[i], z = edge[i];
			if (dist[y] > dist[x] + z)
			{
				dist[y] = dist[x] + z;
				heap.push(make_pair(-dist[y], y));
			}
		}
	}
	if (dist[n] == 0x3f3f3f3f)  puts("-1");
	else for (int i = 1; i <= n; i++) cout << dist[i] << " ";
}

int main()
{
	cin >> n >> m >> s; // 读入点数/边数/起点
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
	}
	dijkstra(s);
	return 0;
}