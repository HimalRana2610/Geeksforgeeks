#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortCycle(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = INT_MAX;
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            vector<int> dist(V, -1);
            dist[u] = 0;

            queue<int> q;
            q.push(u);

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                for (int neighbour : adj[node])
                {
                    if ((node == u && neighbour == v) || (node == v && neighbour == u))
                    {
                        continue;
                    }

                    if (dist[neighbour] == -1)
                    {
                        dist[neighbour] = dist[node] + 1;
                        q.push(neighbour);
                    }
                }
            }

            if (dist[v] != -1)
            {
                ans = min(ans, dist[v] + 1);
            }
        }

        if (ans == INT_MAX)
        {
            return -1;
        }

        return ans;
    }
};