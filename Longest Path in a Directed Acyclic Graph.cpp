#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, vector<vector<pair<int, int>>> &adj, vector<int> &visited, stack<int> &st)
    {
        visited[node] = 1;
        for (auto &neighbour : adj[node])
        {
            if (!visited[neighbour.first])
            {
                dfs(neighbour.first, adj, visited, st);
            }
        }
        st.push(node);
    }

    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(V);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }

        stack<int> st;
        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, st);
            }
        }

        vector<int> ans(V, INT_MIN);
        ans[src] = 0;

        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            if (ans[node] == INT_MIN)
            {
                continue;
            }

            for (auto &neighbour : adj[node])
            {
                ans[neighbour.first] = max(ans[neighbour.first], ans[node] + neighbour.second);
            }
        }

        return ans;
    }
};