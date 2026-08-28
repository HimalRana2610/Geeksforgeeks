#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isNegativeWeightCycle(int V, vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;

        for (int i = 0; i < V - 1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int u = edges[j][0], v = edges[j][1], w = edges[j][2];
                if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                return true;
            }
        }

        return false;
    }
};