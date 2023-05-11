#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> strs(4);
    for (int i = 0; i < 4; i++)
        cin >> strs[i];
    int max_similarity = 0;
    vector<vector<int>> max_pairs;
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            string s1 = strs[i], s2 = strs[j];
            int m = s1.size(), n = s2.size();
            vector<vector<int>> dp(m + 1, vector<int>(n + 1));
            for (int k = 1; k <= m; k++)
            {
                for (int l = 1; l <= n; l++)
                {
                    if (s1[k - 1] == s2[l - 1])
                        dp[k][l] = dp[k - 1][l - 1] + 1;
                    else
                        dp[k][l] = max(dp[k - 1][l], dp[k][l - 1]);
                }
            }
            if (dp[m][n] > max_similarity)
            {
                max_similarity = dp[m][n];
                max_pairs.clear();
                max_pairs.push_back({i, j});
            }
            else if (dp[m][n] == max_similarity)
            {
                max_pairs.push_back({i, j});
            }
        }
    }
    for (auto pair : max_pairs)
    {
        cout << strs[pair[0]] << " " << strs[pair[1]] << " " << max_similarity << endl;
    }
    return 0;
}