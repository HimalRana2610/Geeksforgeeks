#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> constructList(vector<vector<int>> &queries)
    {
        vector<int> ans = {0};
        int current = 0;

        for (int i = 0; i < queries.size(); i++)
        {
            if (queries[i][0] == 0)
            {
                ans.push_back(current ^ queries[i][1]);
            }
            else
            {
                current ^= queries[i][1];
            }
        }

        for (int i = 0; i < ans.size(); i++)
        {
            ans[i] ^= current;
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};