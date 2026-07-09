#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool is_valid(int r, int c, int n, int m)
    {
        return r >= 0 && c >= 0 && r < n && c < m;
    }

    void bfs(vector<vector<int>> &strength, int n, int m, queue<pair<int, int>> &q, vector<vector<bool>> &can_reach)
    {
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        while (!q.empty())
        {
            int r = q.front().first, c = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int nr = r + dirs[k].first, nc = c + dirs[k].second;
                if (is_valid(nr, nc, n, m) && !can_reach[nr][nc] && strength[nr][nc] >= strength[r][c])
                {
                    can_reach[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

    int countCoordinates(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int, int>> p, q;
        vector<vector<bool>> can_reach_p(n, vector<bool>(m, false)), can_reach_q(n, vector<bool>(m, false));

        for (int i = 0; i < m; i++)
        {
            p.push({0, i});
            can_reach_p[0][i] = true;

            q.push({n - 1, i});
            can_reach_q[n - 1][i] = true;
        }
        for (int i = 0; i < n; i++)
        {
            p.push({i, 0});
            can_reach_p[i][0] = true;

            q.push({i, m - 1});
            can_reach_q[i][m - 1] = true;
        }

        bfs(mat, n, m, p, can_reach_p);
        bfs(mat, n, m, q, can_reach_q);

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (can_reach_p[i][j] && can_reach_q[i][j])
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};  