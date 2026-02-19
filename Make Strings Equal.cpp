#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(string &s, string &t, vector<vector<char>> &transform, vector<int> &cost)
    {
        vector<vector<int>> dist(26, vector<int>(26, INT_MAX));
        for (int i = 0; i < 26; i++)
        {
            dist[i][i] = 0;
        }

        for (int i = 0; i < transform.size(); i++)
        {
            int from = transform[i][0] - 'a';
            int to = transform[i][1] - 'a';
            dist[from][to] = min(dist[from][to], cost[i]);
        }

        for (int k = 0; k < 26; k++)
        {
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == t[i])
            {
                continue;
            }

            int minCharCost = INT_MAX;
            for (int c = 0; c < 26; c++)
            {
                int costFromS = dist[s[i] - 'a'][c], costFromT = dist[t[i] - 'a'][c];
                if (costFromS != INT_MAX && costFromT != INT_MAX)
                {
                    minCharCost = min(minCharCost, costFromS + costFromT);
                }
            }

            if (minCharCost == INT_MAX)
            {
                return -1;
            }

            ans += minCharCost;
        }

        return ans;
    }
};