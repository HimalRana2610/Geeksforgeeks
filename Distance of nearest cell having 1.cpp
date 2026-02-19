#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> nearest(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<int> dirX = {-1, 0, 1, 0};
        vector<int> dirY = {0, 1, 0, -1};

        while (!q.empty())
        {
            auto cell = q.front();
            q.pop();
            int x = cell.first;
            int y = cell.second;

            for (int d = 0; d < 4; d++)
            {
                int newX = x + dirX[d];
                int newY = y + dirY[d];

                if (newX >= 0 && newX < n && newY >= 0 && newY < m)
                {
                    if (dist[newX][newY] > dist[x][y] + 1)
                    {
                        dist[newX][newY] = dist[x][y] + 1;
                        q.push({newX, newY});
                    }
                }
            }
        }

        return dist;
    }
};