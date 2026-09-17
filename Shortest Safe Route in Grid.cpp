#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool is_safe(vector<vector<int>> &mat, int x, int y)
    {
        int n = mat.size(), m = mat[0].size();
        if (mat[x][y] != 1)
        {
            return false;
        }

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dirs[i].first, ny = y + dirs[i].second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == 0)
            {
                return false;
            }
        }

        return true;
    }

    int shortestPath(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<vector<int>> q;

        for (int i = 0; i < n; i++)
        {
            if (is_safe(mat, i, 0))
            {
                q.push({i, 0, 1});
                mat[i][0] = -1;
            }
        }

        while (!q.empty())
        {
            int x = q.front()[0], y = q.front()[1], dist = q.front()[2];
            q.pop();

            if (y == m - 1)
            {
                return dist;
            }

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dirs[i].first, ny = y + dirs[i].second;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && is_safe(mat, nx, ny))
                {
                    q.push({nx, ny, dist + 1});
                    mat[nx][ny] = -1;
                }
            }
        }

        return -1;
    }
};