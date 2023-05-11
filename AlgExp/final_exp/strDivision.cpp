// #include <cstring>
// #include <iostream>
// using namespace std;
// int x, y;
// string s;
// int num[15][15];
// long long dp[15][15];
// int main()
// {
//     cin >> x >> y >> s;
//     for (int i = 0; i < x; i++)
//     {
//         for (int j = i; j < x; j++)
//         {
//             num[i + 1][j + 1] = num[i + 1][j] * 10 + s[j] - '0';
//         }
//     }
//     memset(dp, -1, sizeof(dp));
//     for (int i = 1; i <= x; i++)
//     {
//         dp[i][0] = num[1][i];
//     }
//     for (int j = 1; j <= y; j++)
//     {
//         for (int i = j + 1; i <= x; i++)
//         {
//             for (int k = j; k < i; k++)
//             {
//                 dp[i][j] = max(dp[i][j], dp[k][j - 1] * num[k + 1][i]);
//             }
//         }
//     }
//     cout << dp[x][y] << endl;
//     return 0;
// }

// 优化版本
#include <cstring>
#include <iostream>
using namespace std;
int x, y;
string s;
int num[15][15];
long long dp[2][15];
int main()
{
    cin >> x >> y >> s;
    for (int i = 0; i < x; i++)
    {
        for (int j = i; j < x; j++)
        {
            num[i + 1][j + 1] = num[i + 1][j] * 10 + s[j] - '0';
        }
    }
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= x; i++)
    {
        dp[0][i] = num[1][i];
    }
    for (int j = 1; j <= y; j++)
    {
        for (int i = j + 1; i <= x; i++)
        {
            for (int k = j; k < i; k++)
            {
                dp[j & 1][i] = max(dp[j & 1][i], dp[(j - 1) & 1][k] * num[k + 1][i]);
            }
        }
    }
    cout << dp[y & 1][x] << endl;
    return 0;
}