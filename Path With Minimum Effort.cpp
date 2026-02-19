#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCostPath(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});

        vector<int> dr = {1, -1, 0, 0}, dc = {0, 0, 1, -1};
        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int cost = top[0], r = top[1], c = top[2];
            if (r == n - 1 && c == m - 1)
            {
                return cost;
            }

            if (cost > dist[r][c])
            {
                continue;
            }

            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m)
                {
                    int stepCost = abs(mat[r][c] - mat[nr][nc]);
                    int newCost = max(cost, stepCost);

                    if (newCost < dist[nr][nc])
                    {
                        dist[nr][nc] = newCost;
                        pq.push({newCost, nr, nc});
                    }
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};