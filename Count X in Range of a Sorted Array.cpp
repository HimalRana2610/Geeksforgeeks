#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countXInRange(vector<int> &arr, vector<vector<int>> &queries)
    {
        int n = arr.size();
        unordered_map<int, vector<int>> pos;

        for (int i = 0; i < n; i++)
        {
            pos[arr[i]].push_back(i);
        }

        vector<int> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            int l = queries[i][0], r = queries[i][1], x = queries[i][2];
            if (pos.find(x) == pos.end())
            {
                ans.push_back(0);
                continue;
            }
            ans.push_back(upper_bound(pos[x].begin(), pos[x].end(), r) - lower_bound(pos[x].begin(), pos[x].end(), l));
        }

        return ans;
    }
};