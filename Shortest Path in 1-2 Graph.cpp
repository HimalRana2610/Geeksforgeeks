#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(V);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        queue<pair<int, int>> q;
        q.push({0, src});

        while (!q.empty())
        {
            int node = q.front().second, d = q.front().first;
            q.pop();

            for (auto &neighbour : adj[node])
            {

                if (d + neighbour.second < dist[neighbour.first])
                {
                    dist[neighbour.first] = d + neighbour.second;
                    q.push({dist[neighbour.first], neighbour.first});
                }
            }
        }

        if (dist[dest] == INT_MAX)
        {
            return -1;
        }

        return dist[dest];
    }
};