#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(vector<vector<int>> &houses)
    {
        int n = houses.size(), ans = 0;
        vector<bool> visited(n, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0});

        while (!pq.empty())
        {
            int cost = pq.top().first, u = pq.top().second;
            pq.pop();

            if (visited[u])
            {
                continue;
            }

            visited[u] = true;
            ans += cost;

            for (int v = 0; v < n; ++v)
            {
                if (!visited[v])
                {
                    pq.push({abs(houses[u][0] - houses[v][0]) + abs(houses[u][1] - houses[v][1]), v});
                }
            }
        }

        return ans;
    }
};