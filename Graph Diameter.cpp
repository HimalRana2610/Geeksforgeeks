#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adj, int current, vector<int> &dist, vector<bool> &visited)
    {
        if (visited[node])
        {
            return;
        }
        if (dist[0] < current)
        {
            dist[0] = current;
            dist[1] = node;
        }

        visited[node] = true;
        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                dfs(neighbor, adj, current + 1, dist, visited);
            }
        }
    }

    int diameter(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> dist = {0, 0};
        vector<bool> visited(V, false);
        dfs(0, adj, 0, dist, visited);

        int temp = dist[1];
        dist = {0, 0};

        fill(visited.begin(), visited.end(), false);
        dfs(temp, adj, 0, dist, visited);

        return dist[0];
    }
};