#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRot(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }

        int ans = 0;
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while (!q.empty())
        {
            int l = q.size();
            bool found = false;

            for (int i = 0; i < l; i++)
            {
                int x = q.front().first, y = q.front().second;
                q.pop();

                for (int j = 0; j < 4; j++)
                {
                    int nx = x + dirs[j][0], ny = y + dirs[j][1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == 1)
                    {
                        mat[nx][ny] = 2;
                        q.push({nx, ny});
                        found = true;
                    }
                }
            }

            if (found)
            {
                ans++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return ans;
    }
};