#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfCells(int r, int c, int u, int d, vector<vector<char>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        if (mat[r][c] == '#')
        {
            return 0;
        }

        vector<vector<int>> up(n, vector<int>(m, INT_MAX));
        up[r][c] = 0;

        queue<pair<int, int>> q;
        q.push({r, c});

        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();

            int current_up = up[x][y];
            int current_down = current_up + (x - r);

            if (x - 1 >= 0 && mat[x - 1][y] == '.' && current_up + 1 <= u && current_up + 1 < up[x - 1][y])
            {
                up[x - 1][y] = current_up + 1;
                q.push({x - 1, y});
            }

            if (x + 1 < n && mat[x + 1][y] == '.' && current_down + 1 <= d && current_up < up[x + 1][y])
            {
                up[x + 1][y] = current_up;
                q.push({x + 1, y});
            }

            if (y - 1 >= 0 && mat[x][y - 1] == '.' && current_up < up[x][y - 1])
            {
                up[x][y - 1] = current_up;
                q.push({x, y - 1});
            }

            if (y + 1 < m && mat[x][y + 1] == '.' && current_up < up[x][y + 1])
            {
                up[x][y + 1] = current_up;
                q.push({x, y + 1});
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (up[i][j] != INT_MAX)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};