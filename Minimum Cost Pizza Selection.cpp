#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumCost(int x, int s, int m, int l, int cs, int cm, int cl)
    {
        vector<int> dp(x + l + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i <= x + l; i++)
        {
            if (dp[i] == INT_MAX)
            {
                continue;
            }
            if (i + s <= x + l)
            {
                dp[i + s] = min(dp[i + s], dp[i] + cs);
            }
            if (i + m <= x + l)
            {
                dp[i + m] = min(dp[i + m], dp[i] + cm);
            }
            if (i + l <= x + l)
            {
                dp[i + l] = min(dp[i + l], dp[i] + cl);
            }
        }

        int ans = INT_MAX;
        for (int i = x; i <= x + l; i++)
        {
            ans = min(ans, dp[i]);
        }

        return ans;
    }
};