#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFinish(int n, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(n);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> in_degree(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int neighbour : adj[i])
            {
                in_degree[neighbour]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (in_degree[i] == 0)
            {
                q.push(i);
            }
        }

        int cnt = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;

            for (int neighbour : adj[node])
            {
                in_degree[neighbour]--;
                if (in_degree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }

        return cnt == n;
    }
};