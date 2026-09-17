#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int palindromicStrings(int n, int k)
    {
        vector<vector<long long>> dp(k + 1, vector<long long>(k + 1, 0));
        for (int i = 0; i <= k; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = (dp[i - 1][j] % 1000000007 + (j * dp[i - 1][j - 1]) % 1000000007) % 1000000007;
                }
            }
        }

        long long ans = 0;
        for (int i = 1; i <= n / 2; i++)
        {
            ans = (ans + dp[k][i]) % 1000000007;
        }

        ans = (ans * 2) % 1000000007;
        if (n & 1)
        {
            ans = (ans + dp[k][n / 2 + 1]) % 1000000007;
        }

        return ans;
    }
};