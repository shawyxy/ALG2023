// #include <iostream>
// #include <algorithm>
// using namespace std;
// const int N = 10010;
// int f[N][N];
// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= i; j++)
//             cin >> f[i][j];
//     for (int i = n - 1; i >= 1; i--)
//         for (int j = 1; j <= i; j++)
//             f[i][j] += max(f[i + 1][j], f[i + 1][j + 1]);
//     cout << f[1][1] << endl;
//     return 0;
// }

// 这段代码中，`f[i][j]`表示从第`i`层第`j`个位置出发，
// 到达底层的最大路径和。我们从底层开始，逐层向上计算每个位置的最大路径和，最后输出顶层位置的最大路径和即可。
// 5 9 12 15 10 6 8 2 18 9 5 19 7 10 4 16
// 9 12 10 18 10 = 38+21 = 59

// 首先定义了一个二维数组f，用来存储每个位置的最大路径和。
// 然后，它从底层开始，逐层向上计算每个位置的最大路径和。对于每个位置，它的最大路径和等于它下一层相邻两个位置的最大路径和中的较大值加上它本身的数值。最后，输出顶层位置的最大路径和即可。
// 这种方法的时间复杂度为O(n^2)，其中n为数塔的层数。

#include <iostream>
#include <vector>
using namespace std;

int maxPeanuts(vector<vector<int>> &field)
{
    int m = field.size();
    int n = field[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = field[0][0];
    for (int i = 1; i < m; i++)
    {
        dp[i][0] = dp[i - 1][0] + field[i][0];
    }
    for (int j = 1; j < n; j++)
    {
        dp[0][j] = dp[0][j - 1] + field[0][j];
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + field[i][j];
        }
    }
    return dp[m - 1][n - 1];
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> field(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> field[i][j];
            }
        }
        cout << maxPeanuts(field) << endl;
    }
    return 0;
}

// 时间复杂度为O(mn)，其中m和n分别为花生田的行数和列数。这是因为该函数需要遍历整个花生田，对每个交叉点进行计算，每次计算的时间复杂度为常数。