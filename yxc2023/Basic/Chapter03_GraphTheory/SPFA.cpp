#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m, s;
const int N = 100010, M = 2 * N;
int head[N], ver[M], edge[M], nxt[M], idx;
int dist[N];
bool visited[N];
queue<int> q;

void add(int x, int y, int z)
{
    idx++;
    ver[idx] = y;
    edge[idx] = z;
    nxt[idx] = head[x];
    head[x] = idx;
}

void spfa(int s)
{
	memset(dist, 0x3f, sizeof(dist));
	dist[s] = 0;
	q.push(s);
	visited[s] = true;
	while (!q.empty())
	{
		int x = q.front(); q.pop();
		visited[x] = false;

		for (int i = head[x]; i != 0; i = nxt[i])
		{
			int y = ver[i], z = edge[i];
			if (dist[y] > dist[x] + z)
			{
				dist[y] = dist[x] + z;
				if (!visited[y])
					q.push(y), visited[y] = true;
			}
		}
	}
	if (dist[n] == 0x3f3f3f3f)  puts("-1");
	else for (int i = 1; i <= n; i++) cout << dist[i] << " ";
}

int main()
{
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add (x, y, z);
	}
	spfa(s);
	return 0;
}