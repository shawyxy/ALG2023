#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200010;
int n, m, ans, cnt, fa[N];
struct edge
{
	int x, y, w;
	bool operator< (const edge &e) const
	{
		return w < e.w;
	}
}edges[N];

// 并查集查找+路径压缩
int find(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

bool kruskal()
{
	sort(edges, edges + m); // 排序
	for (int i = 1; i <= n; i++) fa[i] = i; // 初始化并查集
	for (int i = 0; i < m; i++) // 枚举每条边
	{
		// 取出这条边的两个顶点所在集合的代表元
		int x = find(edges[i].x);
		int y = find(edges[i].y);
		if (x != y) // 不在同一个集合
		{
			fa[x] = y; // 将x所在集合合并到y的
			ans += edges[i].w;
			cnt++; // 加入最小生成树边集中
		}
	}
	return cnt == n - 1;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		edges[i] = {x, y, z};
	}
	if (kruskal()) cout << ans << endl;
	else puts("orz");
	return 0;
}