#include <iostream>
using namespace std;

const int N = 100010;
int path[N];
bool visited[N];
int n;

void dfs(int x)
{
	if (x == n)
	{
		for (int i = 0; i < n; i++) printf("    %d", path[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] != true)
		{
			path[x] = i;
			visited[i] = true;
			dfs(x + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	while (cin >> n)
	{
		dfs(0);
	}
	return 0;
}