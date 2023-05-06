#include <iostream>
using namespace std;
const int N = 100010, M = 10010;
int p[N], s[M];
int ne[N];

int main()
{
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	cin >> m;
	for (int i = 1; i <= m; i++) scanf("%d", &s[i]);

	for (int i = 2, j = 0; i <= n; i++)
	{
		while (j && p[i] != p[j + 1]) j = ne[j];
		if (p[i] == p[j + 1]) j++;
		ne[i] = j;
	}

	for (int i = 1, j = 0; i <= m; i++)
	{
		while (j && s[i] != p[j + 1]) j = ne[j];
		if (s[i] == p[j + 1]) j++;
		if (j == n)
		{
			printf("%d ", i - n);
			j = ne[j];
		}
	}

	return 0;
}