#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst)
    {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], 0});
            adj[edges[i][1]].push_back({edges[i][0], 1});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[src] = 0;

        deque<int> dq;
        dq.push_front(src);

        while (!dq.empty())
        {
            int node = dq.front();
            dq.pop_front();

            for (auto &neighbour : adj[node])
            {
                if (dist[node] + neighbour.second < dist[neighbour.first])
                {
                    dist[neighbour.first] = dist[node] + neighbour.second;
                    if (neighbour.second == 0)
                    {
                        dq.push_front(neighbour.first);
                    }
                    else
                    {
                        dq.push_back(neighbour.first);
                    }
                }
            }
        }

        if (dist[dst] == INT_MAX)
        {
            return -1;
        }

        return dist[dst];
    }
};