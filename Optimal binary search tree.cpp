#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(vector<int> &keys, vector<int> &freq)
    {
        int n = keys.size();
        vector<int> prefix(n, 0);
        prefix[0] = freq[0];

        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + freq[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int l = 1; l <= n; l++)
        {
            for (int i = 0; i <= n - l; i++)
            {
                int j = i + l - 1;
                dp[i][j] = INT_MAX;

                for (int r = i; r <= j; r++)
                {
                    int cost = ((r > i) ? dp[i][r - 1] : 0) + ((r < j) ? dp[r + 1][j] : 0) + (prefix[j] - (i > 0 ? prefix[i - 1] : 0));
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }

        return dp[0][n - 1];
    }
};