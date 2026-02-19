#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPath(int V, int a, int b, vector<vector<int>> &edges)
    {
        vector<vector<tuple<int, int, int>>> adj(V);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1], w1 = edges[i][2], w2 = edges[i][3];
            adj[u].push_back({v, w1, w2});
            adj[v].push_back({u, w1, w2});
        }

        vector<vector<int>> dist(V, vector<int>(2, INT_MAX));
        dist[a][0] = 0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, a, 0});

        while (!pq.empty())
        {
            int d = get<0>(pq.top()), u = get<1>(pq.top()), curved_used = get<2>(pq.top());
            pq.pop();

            if (d > dist[u][curved_used])
            {
                continue;
            }

            for (auto &neighbor : adj[u])
            {
                int v = get<0>(neighbor), w1 = get<1>(neighbor), w2 = get<2>(neighbor);
                if (dist[u][curved_used] + w1 < dist[v][curved_used])
                {
                    dist[v][curved_used] = dist[u][curved_used] + w1;
                    pq.push({dist[v][curved_used], v, curved_used});
                }
                if (curved_used == 0 && dist[u][0] + w2 < dist[v][1])
                {
                    dist[v][1] = dist[u][0] + w2;
                    pq.push({dist[v][1], v, 1});
                }
            }
        }

        int ans = min(dist[b][0], dist[b][1]);
        return ans == INT_MAX ? -1 : ans;
    }
};