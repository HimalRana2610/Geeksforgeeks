#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalWays(vector<int> &arr, int target)
    {
        int n = arr.size(), sum = accumulate(arr.begin(), arr.end(), 0);
        vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, 0));
        dp[0][sum] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= 2 * sum; j++)
            {
                if (j + arr[i - 1] <= 2 * sum)
                {
                    dp[i][j + arr[i - 1]] += dp[i - 1][j];
                }

                if (j - arr[i - 1] >= 0)
                {
                    dp[i][j - arr[i - 1]] += dp[i - 1][j];
                }
            }
        }

        return dp[n][target + sum];
    }
};