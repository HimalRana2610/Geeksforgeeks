#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int validGroups(string &s)
    {
        int n = s.length(), m = n * 9;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= m; i++)
        {
            dp[n][i] = 1;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= m; j++)
            {
                int current = 0;
                for (int k = i; k < n; k++)
                {
                    current += s[k] - '0';
                    if (current >= j)
                    {
                        dp[i][j] += dp[k + 1][current];
                    }
                }
            }
        }

        return dp[0][0];
    }
};