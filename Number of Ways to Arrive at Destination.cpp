#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPaths(int V, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(V);
        for (auto &e : edges)
        {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<long long> dist(V, LLONG_MAX);
        dist[0] = 0;

        vector<long long> ways(V, 0);
        ways[0] = 1;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty())
        {
            auto top = pq.top();
            long long d = top.first;
            int u = top.second;
            pq.pop();

            if (d > dist[u])
            {
                continue;
            }

            for (auto &p : adj[u])
            {
                int v = p.first;
                long long w = p.second;

                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }
                else if (dist[u] + w == dist[v])
                {
                    ways[v] += ways[u];
                }
            }
        }

        return ways[V - 1];
    }
};