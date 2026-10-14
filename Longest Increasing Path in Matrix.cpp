#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(vector<vector<int>> &matrix, int x, int y, int n, int m, vector<vector<int>> &dp)
    {
        if (dp[x][y] != -1)
        {
            return dp[x][y];
        }

        int ans = 1;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dirs[i].first, ny = y + dirs[i].second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] > matrix[x][y])
            {
                ans = max(ans, 1 + dfs(matrix, nx, ny, n, m, dp));
            }
        }

        return dp[x][y] = ans;
    }

    int longIncPath(vector<vector<int>> &matrix, int n, int m)
    {
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans = max(ans, dfs(matrix, i, j, n, m, dp));
            }
        }

        return ans;
    }
};