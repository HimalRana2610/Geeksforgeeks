#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &ans)
    {
        visited[node] = 1;
        for (int neighbour : adj[node])
        {
            if ((visited[neighbour] == 1) || (visited[neighbour] == 0 && !dfs(neighbour, adj, visited, ans)))
            {
                return false;
            }
            else if (visited[neighbour] == 0)
            {
                if (!dfs(neighbour, adj, visited, ans))
                {
                    return false;
                }
            }
        }

        visited[node] = 2;
        ans.push_back(node);

        return true;
    }

    vector<int> findOrder(int n, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(n);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> visited(n, 0), ans;

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            {
                if (!dfs(i, adj, visited, ans))
                {
                    return {};
                }
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};