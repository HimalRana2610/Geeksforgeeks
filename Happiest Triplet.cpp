#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> smallestDiff(vector<int> &a, vector<int> &b, vector<int> &c)
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());

        int i = 0, j = 0, k = 0, diff = INT_MAX;
        vector<int> ans(3);

        while (i < a.size() && j < b.size() && k < c.size())
        {
            int low = min({a[i], b[j], c[k]}), high = max({a[i], b[j], c[k]});
            if (diff > high - low)
            {
                diff = high - low;
                ans[0] = high, ans[1] = a[i] + b[j] + c[k] - (high + low), ans[2] = low;
            }

            if (a[i] == low)
            {
                i++;
            }
            else if (b[j] == low)
            {
                j++;
            }
            else
            {
                k++;
            }
        }

        return ans;
    }
};