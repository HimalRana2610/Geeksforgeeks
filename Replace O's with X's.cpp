#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int i, int j, char target, char replacement)
    {
        int n = grid.size(), m = grid[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != target)
        {
            return;
        }

        grid[i][j] = replacement;

        dfs(grid, i + 1, j, target, replacement);
        dfs(grid, i - 1, j, target, replacement);
        dfs(grid, i, j + 1, target, replacement);
        dfs(grid, i, j - 1, target, replacement);
    }

    void fill(vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'O')
                {
                    grid[i][j] = '.';
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (grid[i][0] == '.')
            {
                dfs(grid, i, 0, '.', 'O');
            }
            if (grid[i][m - 1] == '.')
            {
                dfs(grid, i, m - 1, '.', 'O');
            }
        }
        for (int j = 0; j < m; j++)
        {
            if (grid[0][j] == '.')
            {
                dfs(grid, 0, j, '.', 'O');
            }
            if (grid[n - 1][j] == '.')
            {
                dfs(grid, n - 1, j, '.', 'O');
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '.')
                {
                    grid[i][j] = 'X';
                }
            }
        }
    }
};