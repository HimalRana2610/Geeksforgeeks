#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries)
    {
        sort(arr.begin(), arr.end());
        vector<int> ans;

        for (int i = 0; i < queries.size(); i++)
        {
            ans.push_back(upper_bound(arr.begin(), arr.end(), queries[i][1]) - lower_bound(arr.begin(), arr.end(), queries[i][0]));
        }

        return ans;
    }
};