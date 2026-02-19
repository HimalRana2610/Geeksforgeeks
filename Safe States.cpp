#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> safeNodes(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        vector<vector<int>> rev_adj(V);
        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++)
        {
            for (int neighbour : adj[i])
            {
                rev_adj[neighbour].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> ans;

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int neighbour : rev_adj[node])
            {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }

        return ans;
    }
};