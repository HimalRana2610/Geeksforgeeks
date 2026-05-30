#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b)
    {
        int n = a.size();
        vector<vector<int>> diff(n, vector<int>(2));

        for (int i = 0; i < n; i++)
        {
            diff[i] = {abs(a[i] - b[i]), i};
        }

        sort(diff.begin(), diff.end(), greater<vector<int>>());

        int i = 0, ans = 0;
        while (i < n && x > 0 && y > 0)
        {
            if (a[diff[i][1]] >= b[diff[i][1]])
            {
                ans += a[diff[i][1]];
                x--;
            }
            else
            {
                ans += b[diff[i][1]];
                y--;
            }
            i++;
        }

        while (i < n && x > 0)
        {
            ans += a[diff[i][1]];
            x--;
            i++;
        }

        while (i < n && y > 0)
        {
            ans += b[diff[i][1]];
            y--;
            i++;
        }

        return ans;
    }
};