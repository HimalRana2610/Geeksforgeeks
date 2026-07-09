#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minInsAndDel(vector<int> &a, vector<int> &b)
    {
        int n = a.size(), m = b.size();
        unordered_map<int, int> pos;

        for (int i = 0; i < m; i++)
        {
            pos[b[i]] = i;
        }

        vector<int> visited;
        for (int i = 0; i < n; i++)
        {
            if (pos.count(a[i]))
            {
                visited.push_back(pos[a[i]]);
            }
        }

        vector<int> lis;
        for (int i = 0; i < visited.size(); i++)
        {
            auto it = lower_bound(lis.begin(), lis.end(), visited[i]);
            if (it == lis.end())
            {
                lis.push_back(visited[i]);
            }
            else
            {
                *it = visited[i];
            }
        }

        int l = lis.size();
        return n + m - 2 * l;
    }
};