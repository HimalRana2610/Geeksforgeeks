#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited)
    {
        visited[node] = true;
        for (int &neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                dfs(neighbour, adj, visited);
            }
        }
    }

    int findMotherVertex(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        vector<bool> visited(V, false);
        int ans = 0;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited);
                ans = i;
            }
        }

        fill(visited.begin(), visited.end(), false);
        dfs(ans, adj, visited);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                return -1;
            }
        }

        return ans;
    }
};