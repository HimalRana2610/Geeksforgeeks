#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> update(int n, vector<int> &updates)
    {
        vector<int> ans(n, 0);
        for (int i = 0; i < updates.size(); i++)
        {
            ans[updates[i] - 1]++;
        }

        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            cnt += ans[i];
            ans[i] = cnt;
        }

        return ans;
    }
};