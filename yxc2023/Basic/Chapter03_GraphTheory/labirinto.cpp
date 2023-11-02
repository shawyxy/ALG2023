#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 110;

queue<pair<int, int>> q;
int n, m;
int gra[N][N];
int dis[N][N]; // 记录某点到原点的距离
pair<int, int> Prev[N][N]; // 记录当前元素的上一个结点

void printPath()
{
    int x = n - 1;
    int y = m - 1;
    while (x != 0 || y != 0)
    {
        printf ("%d %d\n", x, y);
        auto t = Prev[x][y];
        x = t.first;
        y = t.second;
    }
}

int bfs()
{
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    memset(dis, -1, sizeof(dis));

    dis[0][0] = 0; // 初始化距离
    q.push({0, 0}); // 将起点入队
    while (!q.empty())
    {
        auto t = q.front(); // 取出队头元素 t
        q.pop(); // 出队
        for (int i = 0; i < 4; i++) // 访问 t 的 4 个邻居
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            // 如果坐标合法且不是墙,并且没有被访问过,则入队
            if ((x >= 0 && x < n && y >= 0 && y < m) && gra[x][y] == 0 && dis[x][y] == -1)
            {
                // path[x][y] = t; // 记录路径
                dis[x][y] = dis[t.first][t.second] + 1;
                Prev[x][y] = t; // 记录上一个合法的元素
                q.push({x, y});
            }
        }
    }

    // 打印
    printPath();

    return dis[n - 1][m - 1];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &gra[i][j]);
    cout << bfs() << endl;
    return 0;
}