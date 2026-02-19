#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCutCost(int n, vector<int> &cuts)
    {
        int m = cuts.size();
        vector<int> cost(m + 2);
        cost[0] = 0;
        cost[m + 1] = n;

        for (int i = 0; i < m; i++)
        {
            cost[i + 1] = cuts[i];
        }

        sort(cost.begin(), cost.end());
        vector<vector<int>> dp(m + 2, vector<int>(m + 2, 0));

        for (int l = 2; l < m + 2; l++)
        {
            for (int i = 0; i + l < m + 2; i++)
            {
                int j = i + l;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + (cost[j] - cost[i]));
                }
            }
        }

        return dp[0][m + 1];
    }
};