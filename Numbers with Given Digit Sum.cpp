#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countWays(int n, int sum)
    {
        if (sum > 9 * n)
        {
            return -1;
        }

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                for (int digit = 0; digit <= 9; digit++)
                {
                    if (j >= digit)
                    {
                        dp[i][j] += dp[i - 1][j - digit];
                    }
                }
            }
        }

        int ans = 0;
        for (int digit = 1; digit <= 9; digit++)
        {
            if (sum >= digit)
            {
                ans += dp[n - 1][sum - digit];
            }
        }

        if (ans == 0)
        {
            return -1;
        }

        return ans;
    }
};