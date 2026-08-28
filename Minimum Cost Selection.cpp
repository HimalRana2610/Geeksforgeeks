#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(vector<vector<int>> &mat)
    {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(3, INT_MAX));
        dp[0] = mat[0];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (j == 0)
                {
                    dp[i][j] = min(dp[i - 1][j + 1], dp[i - 1][j + 2]) + mat[i][j];
                }
                else if (j == 1)
                {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j + 1]) + mat[i][j];
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j - 2], dp[i - 1][j - 1]) + mat[i][j];
                }
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};