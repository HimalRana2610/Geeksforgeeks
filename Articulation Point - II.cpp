#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<bool> &ap, int &time)
    {
        disc[node] = low[node] = time++;
        int children = 0;

        for (int neighbour : adj[node])
        {
            if (disc[neighbour] == -1)
            {
                children++;
                parent[neighbour] = node;
                dfs(neighbour, adj, disc, low, parent, ap, time);
                low[node] = min(low[node], low[neighbour]);

                if (parent[node] == -1 && children > 1)
                {
                    ap[node] = true;
                }
                if (parent[node] != -1 && low[neighbour] >= disc[node])
                {
                    ap[node] = true;
                }
            }
            else if (neighbour != parent[node])
            {
                low[node] = min(low[node], disc[neighbour]);
            }
        }
    }

    vector<int> articulationPoints(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> disc(V, -1), low(V, -1), parent(V, -1);
        vector<bool> ap(V, false);
        int time = 0;

        for (int i = 0; i < V; i++)
        {
            if (disc[i] == -1)
            {
                dfs(i, adj, disc, low, parent, ap, time);
            }
        }

        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (ap[i])
            {
                ans.push_back(i);
            }
        }

        if (ans.empty())
        {
            ans.push_back(-1);
        }

        return ans;
    }
};