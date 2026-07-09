#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countStrings(int n, int k)
    {
        if (k > n - 1)
        {
            return 0;
        }

        vector<vector<int>> dp(k + 1, vector<int>(2, 0));
        dp[0][0] = 1;
        dp[0][1] = 1;

        for (int i = 2; i <= n; i++)
        {
            vector<vector<int>> new_dp(k + 1, vector<int>(2, 0));
            for (int j = 0; j <= k; j++)
            {
                new_dp[j][0] = (new_dp[j][0] + dp[j][0]) % 1000000007;
                new_dp[j][0] = (new_dp[j][0] + dp[j][1]) % 1000000007;
                new_dp[j][1] = (new_dp[j][1] + dp[j][0]) % 1000000007;

                if (j + 1 <= k)
                {
                    new_dp[j + 1][1] = (new_dp[j + 1][1] + dp[j][1]) % 1000000007;
                }
            }
            dp = new_dp;
        }

        return (dp[k][0] + dp[k][1]) % 1000000007;
    }
};