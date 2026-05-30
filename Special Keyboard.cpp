#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int optimalKeys(int n)
    {
        if (n <= 6)
        {
            return n;
        }

        vector<int> dp(n);
        for (int i = 1; i <= 6; i++)
        {
            dp[i - 1] = i;
        }

        for (int i = 7; i <= n; i++)
        {
            dp[i - 1] = max({2 * dp[i - 4], 3 * dp[i - 5], 4 * dp[i - 6]});
        }

        return dp[n - 1];
    }
};