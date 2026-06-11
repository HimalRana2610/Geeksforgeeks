#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> freqInRange(vector<int> &arr, vector<vector<int>> &queries)
    {
        map<int, vector<int>> mp;
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]].push_back(i);
        }

        vector<int> ans;
        for (auto &q : queries)
        {
            int l = q[0], r = q[1], x = q[2];
            if (mp.find(x) == mp.end())
            {
                ans.push_back(0);
                continue;
            }

            ans.push_back(upper_bound(mp[x].begin(), mp[x].end(), r) - lower_bound(mp[x].begin(), mp[x].end(), l));
        }

        return ans;
    }
};