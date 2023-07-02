#include <iostream>
#include <string>
#include <vector>
using namespace std;

char* find_lcs(const char *s1, const char *s2) {
    int m = strlen(s1); int n = strlen(s2);
    int i, j, dp[m+1][n+1];
    for (i=0; i<=m; i++)
        for (j=0; j<=n; j++) dp[i][j] = 0;
    for (i=1; i<=m; i++) {
        for (j=1; j<=n; j++) {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];} }
    i = m, j = n;
    char* lcs = new char[dp[m][n]+1]; // 声明一个动态数组
    // lcs[dp[m][n]] = '0';
    while (i > 0 && j > 0) {
        if (s1[i-1] == s2[j-1]) {
            lcs[dp[i][j]-1] = s1[i-1];i--; j--;
        } else if (dp[i-1][j] > dp[i][j-1]) i--;
       else  j--; 
   }
   return lcs; // 返回最长公共子序列
}

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
        cout << strs[pair[0]] << " " << strs[pair[1]] << " " << max_similarity << " ";
        char* lcs = find_lcs(strs[pair[0]].c_str(), strs[pair[1]].c_str()); 
        cout << lcs << endl;
        delete[] lcs;
    }
    return 0;
}
