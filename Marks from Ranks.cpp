#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank)
    {
        int n = l.size();
        vector<long long> ranks(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            ranks[i + 1] = ranks[i] + r[i] - l[i] + 1;
        }

        vector<int> ans;
        for (int i = 0; i < rank.size(); i++)
        {
            int idx = lower_bound(ranks.begin(), ranks.end(), rank[i]) - ranks.begin();
            rank[i] -= ranks[idx - 1];
            ans.push_back(l[idx - 1] + rank[i] - 1);
        }

        return ans;
    }
};