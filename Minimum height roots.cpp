#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minHeightRoot(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> degree(V);
        for (int i = 0; i < V; i++)
        {
            degree[i] = adj[i].size();
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (degree[i] == 1)
            {
                q.push(i);
            }
        }

        int rem = V;
        while (rem > 2)
        {
            int cnt = q.size();
            rem -= cnt;

            for (int i = 0; i < cnt; i++)
            {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node])
                {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1)
                    {
                        q.push(neighbor);
                    }
                }

                degree[node] = 0;
            }
        }

        vector<int> ans;
        while (!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};