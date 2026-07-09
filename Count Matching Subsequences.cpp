#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countWays(string &s1, string &s2)
    {
        int n = s1.length(), m = s2.length();
        vector<int> dp(m + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j >= 1; j--)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[j] = (dp[j] + dp[j - 1]) % 1000000007;
                }
            }
        }

        return dp[m];
    }
};