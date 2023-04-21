// int a[N][N], S[N][N];
// // 注意操作的是差分矩阵
// void insert(int x1, int y1, int x2, int y2, int c)
// {
//     a[x1][y1] += c;
//     a[x2 + 1][y1] -= c;
//     a[x1][y2 + 1] -= c;
//     a[x2 + 1][y2 + 1] += c;
// }
// // 读入原矩阵,它是差分矩阵的前缀和矩阵,因此用S
// for (int i = 1; i <= n; i++)
//     for (int j = 1; j <= m; j++)
//         scanf("%d", &S[i][j]);

// // 初始化差分矩阵
// for (int i = 1; i <= n; i++)
//     for (int j = 1; j <= m; j++)
//         insert(i, j, i, j, S[i][j]);

// // 处理查询
// while(q--)
// {
//     // 读入坐标和常数c
//     int x1, y1, x2, y2, c;
//     cin >> x1 >> y1 >> x2 >> y2 >> c;
//     // 在两点范围内插入
//     insert(x1, y1, x2, y2, c);
// }
// // 由于修改了差分矩阵的元素,因此要更新前缀和矩阵
// for (int i = 1; i <= n; i++)
//     for (int j = 1; j <= m; j++)
//         S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + a[i][j];

int a[N], S[N];5
void insert(int l, int r, int c)
{
    a[l] += c;
    a[r + 1] -= c;
}
for(int i = 1; i <= n; i++) scanf("%d", &S[i]); // 读入S[i]
for(int i = 1; i <= n; i++) insert(i, i, S[i]); // 初始化差分数组a[i]
while(某次询问)
{
    int r, l, c;
    cin >> r >> l >> c; // 读入区间[l, r]和常数c
    insert(l, r, c)     // 插入
}

for(int i = 1; i <= n; i++) a[i] += a[i - 1] // 差分数组自己重新计算修改后的前缀和
for(int i = 1; i <= n; i++) cout << a[i] << " "; // 输出前缀和