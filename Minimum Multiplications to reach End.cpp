#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSteps(vector<int> &arr, int start, int end)
    {
        vector<bool> visited(1000, false);
        visited[start] = true;

        queue<pair<int, int>> q;
        q.push({start, 0});

        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                int current = q.front().first, dist = q.front().second;
                q.pop();

                if (current == end)
                {
                    return dist;
                }

                for (int i = 0; i < arr.size(); i++)
                {
                    int next = (current * arr[i]) % 1000;
                    if (!visited[next])
                    {
                        visited[next] = true;
                        q.push({next, dist + 1});
                    }
                }
            }
        }

        return -1;
    }
};