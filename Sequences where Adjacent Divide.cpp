#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int count(int n, int m)
    {
        vector<vector<int>> factors(m + 1), multiples(m + 1);
        for (int i = 1; i <= m; i++)
        {
            for (int j = i; j <= m; j += i)
            {
                factors[j].push_back(i);
                if (j != i)
                {
                    multiples[i].push_back(j);
                }
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= m; i++)
        {
            dp[1][i] = 1;
        }

        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                for (int k : factors[j])
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 1000000007;
                }
                for (int k : multiples[j])
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 1000000007;
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= m; i++)
        {
            ans = (ans + dp[n][i]) % 1000000007;
        }

        return ans;
    }
};