#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countWays(int n, int m)
    {
        vector<int> dp(n + 1);
        for (int i = 0; i <= n; i++)
        {
            if (i < m)
            {
                dp[i] = 1;
            }
            else if (i == m)
            {
                dp[i] = 2;
            }
            else
            {
                dp[i] = (dp[i - 1] + dp[i - m]) % 1000000007;
            }
        }

        return dp[n];
    }
};