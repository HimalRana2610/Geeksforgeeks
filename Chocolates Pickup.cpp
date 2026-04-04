#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int next_max(int r, int c1, int c2, int m, vector<vector<vector<int>>> &dp)
    {
        vector<int> dir = {-1, 0, 1};
        int ans = 0;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int d1 = dir[i], d2 = dir[j];
                if (c1 + d1 >= 0 && c1 + d1 < m && c2 + d2 >= 0 && c2 + d2 < m)
                {
                    ans = max(ans, dp[r + 1][c1 + d1][c2 + d2]);
                }
            }
        }

        return ans;
    }

    int maxChocolate(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dp[n - 1][i][j] = (grid[n - 1][i]) + ((i != j) ? grid[n - 1][j] : 0);
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k < m; k++)
                {
                    dp[i][j][k] = (grid[i][j]) + ((j != k) ? grid[i][k] : 0) + next_max(i, j, k, m, dp);
                }
            }
        }

        return dp[0][0][m - 1];
    }
};