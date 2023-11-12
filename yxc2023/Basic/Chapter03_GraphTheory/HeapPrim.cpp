#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n, m, ans, cnt;
const int N = 5010;

int gra[N][N], minDist[N];
bool visited[N]; // 标记x顶点是否是第一次出队
// <-minDist[x], x> 距离, 编号
priority_queue<pair<int, int>> heap;

bool prim(int s)
{
	memset(minDist, 0x3f, sizeof(minDist));
	minDist[s] = 0, ans = 0;
	heap.push(make_pair(0, s));
	while (!heap.empty())
	{
		int x = heap.top().second; heap.pop(); // 出队
		if (visited[x]) continue; // 只对第一次出队的顶点操作
		visited[x] = true; // 标记
		ans += minDist[x]; cnt++; // 累计权值,记录出队过的顶点数
		for (int y = 1; y <= n; y++)
			if (minDist[y] > gra[x][y]) // 如果通过x能够缩短距离
			{
				minDist[y] = gra[x][y]; // 更新minDist数组
				heap.push(make_pair(-minDist[y], y)); // 可以更新则入队
			}
	}
	return cnt == n;
}

int main()
{
	cin >> n >> m;
	memset(gra, 0x3f, sizeof(gra));
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		if (x != y) // 排除自环
		{
			gra[x][y] = min(gra[x][y], z); // 取最小的权重
			gra[y][x] = min(gra[y][x], z);
		}
	}
	if (prim(1)) cout << ans << endl;
	else puts("orz");
	return 0;
}
