#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;
int n, m;
int in[N];
vector<int> ver[N], topo;
queue<int> q;

bool TopoSort()
{
	for (int i = 1; i <= n; i++)
		if (in[i] == 0) q.push(i);

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		topo.push_back(x);

		for (auto &y : ver[x])
			if (--in[y] == 0) q.push(y);
	}

	return topo.size() == n;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		ver[a].push_back(b);
		in[b]++;
	}
	if (!TopoSort()) puts("-1");
	else for (auto &e : topo) printf("%d ", e);

	return 0;
}