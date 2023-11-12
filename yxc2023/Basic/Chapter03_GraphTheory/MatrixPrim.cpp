#include <iostream>
#include <cstring>

using namespace std;

const int N = 5010;
int n, m, ans, cnt;
// minDist存储每个顶点到已选集合的最短距离，pre存储每个顶点的前驱
int gra[N][N], minDist[N], pre[N];
bool visited[N]; // 标记顶点是否已经加入已选集合(最小生成树)中
bool prim(int s)
{
	memset(minDist, 0x3f, sizeof(minDist));
	minDist[s] = 0, ans = 0;	// ans是最小生成树的权值和
	for (int i = 0; i < n; i++) // 循环n次，每次选择一个顶点加入到已选集合中
	{
		int x = -1;					 // x表示当前要选择的顶点
		for (int y = 1; y <= n; y++) // 遍历所有顶点，找到距离已选集合最近的顶点
		{
			// 如果顶点y没有被访问过，且距离比当前的x小，就更新x为y
			if (!visited[y] && (x == -1 || minDist[y] < minDist[x]))
				x = y;
		}
		if (i)
			ans += minDist[x]; // 如果不是第一次循环，就将x的距离累加到权值和中
		if (i && minDist[x] == 0x3f3f3f3f)
			return false; // 如果找不到最小的边，说明图不连通，返回false
		// 更新其他顶点到已选集合的距离
		for (int y = 1; y <= n; y++)
		{
			if (minDist[y] > gra[x][y]) // 如果通过x能够缩短距离
			{
				minDist[y] = gra[x][y]; // 更新minDist数组
				pre[y] = x;				// 更新pre数组，记录y的前驱节点是x
			}
		}
		visited[x] = true;
	}
	return true; // 如果找到了n-1条边，说明图连通，返回true
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
	// 打印路径
	// for (int i = 1; i <= n; i++) // 对于每个顶点
	// {
	// 	for (int v = i; v != 0; v = pre[v]) // 从当前顶点开始反向追踪
	// 		cout << v << " <- ";
	// 	cout << "1" << endl; // 源顶点是路径的起点
	// }

	return 0;
}
