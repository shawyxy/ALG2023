#include <iostream>
#include <cstring>

using namespace std;

int n, m, s;
const int N = 10010, INF = 1e9, M = 2 * N;
int gra[N][N], dist[M];
bool visited[N];

void dijkstra(int s)
{
	// 初始化
	memset(dist, 0x3f, sizeof(dist));
	memset(visited, false, sizeof(visited));
	dist[s] = 0;
	// 重复操作n次，每次选择一个最近的点
	for (int i = 0; i < n; i++)
	{
		// 在未被访问过的点中选择一个最近的点x
		// min_dist记录最小距离
		int x, min_dist = INF;
		for (int j = 1; j <= n; j++)
		{
			// 没有被访问过,且距离更小则更新
			if (!visited[j] && dist[j] < min_dist)
			{
				x = j;
				min_dist = dist[j];
			}
		}
		visited[x] = true; // 标记x已被访问
		// 用x来更新其他未访问过的点的距离
		for (int y = 1; y <= n; y++) // 松弛操作
			dist[y] = min(dist[y], dist[x] + gra[x][y]);
	}
	if (dist[n] == 0x3f3f3f3f)  puts("-1");
	else for (int i = 1; i <= n; i++) cout << dist[i] << " ";
}

int main()
{
	cin >> n >> m >> s; // 读入点数/边数/起点
	memset(gra, 0x3f, sizeof(gra));
	// 如果图中可能存在重边,那么只读取那个较小的
	for (int i = 0; i < m; i++) // 注意是读入边,所以是m
	{
		int x, y, z;
		cin >> x >> y >> z;
		gra[x][y] = min(gra[x][y], z);
	}
	for (int i = 1; i <= n; i++) gra[i][i] = 0;
	dijkstra(s);
	return 0;
}