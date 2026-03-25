#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCycle(int V, vector<vector<int>> &edges)
    {
        vector<int> adj(V, -1);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]] = edges[i][1];
        }

        vector<bool> visited(V, false);
        int ans = -1;

        for (int i = 0; i < V; i++)
        {
            if (visited[i])
            {
                continue;
            }

            unordered_map<int, int> depth;
            int node = i, step = 0;

            while (node != -1)
            {
                if (depth.count(node))
                {
                    ans = max(ans, step - depth[node]);
                    break;
                }
                if (visited[node])
                {
                    break;
                }

                visited[node] = true;
                depth[node] = step;
                node = adj[node];
                step++;
            }
        }

        return ans;
    }
};