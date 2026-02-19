#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int tsp(vector<vector<int>> &cost)
    {
        int n = cost.size();
        int l = 1 << n;

        if (n == 1)
        {
            return 0;
        }

        vector<vector<int>> dp(l, vector<int>(n, INT_MAX));
        dp[1][0] = 0;

        for (int i = 1; i < l; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!(i & (1 << j)) || dp[i][j] == INT_MAX)
                {
                    continue;
                }

                for (int k = 0; k < n; k++)
                {
                    if (i & (1 << k))
                    {
                        continue;
                    }

                    int next = i | (1 << k);
                    dp[next][k] = min(dp[next][k], dp[i][j] + cost[j][k]);
                }
            }
        }

        int ans = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            if (dp[l - 1][i] != INT_MAX)
            {
                ans = min(ans, dp[l - 1][i] + cost[i][0]);
            }
        }

        return ans;
    }
};