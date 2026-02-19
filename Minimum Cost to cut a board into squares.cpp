#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(int n, int m, vector<int> &x, vector<int> &y)
    {
        sort(x.rbegin(), x.rend());
        sort(y.rbegin(), y.rend());

        int vertical = 1, horizontal = 1, i = 0, j = 0, ans = 0;
        while (i < m - 1 && j < n - 1)
        {
            if (x[i] >= y[j])
            {
                ans += x[i++] * horizontal;
                vertical++;
            }
            else
            {
                ans += y[j++] * vertical;
                horizontal++;
            }
        }

        while (i < m - 1)
        {
            ans += x[i++] * horizontal;
        }
        while (j < n - 1)
        {
            ans += y[j++] * vertical;
        }

        return ans;
    }
};