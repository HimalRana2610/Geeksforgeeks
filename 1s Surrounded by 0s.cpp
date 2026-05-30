#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int cntOnes(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            if (grid[i][0] == 1)
            {
                grid[i][0] = 0;
                q.push({i, 0});
            }

            if (grid[i][m - 1] == 1)
            {
                grid[i][m - 1] = 0;
                q.push({i, m - 1});
            }
        }

        for (int j = 0; j < m; j++)
        {
            if (grid[0][j] == 1)
            {
                grid[0][j] = 0;
                q.push({0, j});
            }

            if (grid[n - 1][j] == 1)
            {
                grid[n - 1][j] = 0;
                q.push({n - 1, j});
            }
        }

        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int nx = x + dirs[k].first, ny = y + dirs[k].second;
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1)
                {
                    grid[nx][ny] = 0;
                    q.push({nx, ny});
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans += grid[i][j];
            }
        }

        return ans;
    }
};