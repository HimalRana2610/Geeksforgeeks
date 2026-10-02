#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minTime(vector<int> &duration, vector<vector<int>> &dependencies)
    {
        int n = duration.size();
        vector<vector<int>> adj(n);
        vector<int> in_degree(n, 0);

        for (int i = 0; i < dependencies.size(); i++)
        {
            adj[dependencies[i][0]].push_back(dependencies[i][1]);
            in_degree[dependencies[i][1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (in_degree[i] == 0)
            {
                q.push(i);
            }
        }

        int visited = 0, ans = 0;
        vector<int> finish_time(duration.begin(), duration.end());

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            visited++;
            ans = max(ans, finish_time[node]);

            for (int next : adj[node])
            {
                finish_time[next] = max(finish_time[next], finish_time[node] + duration[next]);
                if (--in_degree[next] == 0)
                {
                    q.push(next);
                }
            }
        }

        if (visited != n)
        {
            return -1;
        }

        return ans;
    }
};