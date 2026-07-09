#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDotProduct(vector<int> &a, vector<int> &b)
    {
        int m = a.size(), n = b.size();
        vector<int> dp(n + 1, -1e9);
        dp[0] = 0;

        for (int i = 1; i <= m; i++)
        {
            for (int j = n; j >= 1; j--)
            {
                dp[j] = max(dp[j], dp[j - 1] + (a[i - 1] * b[j - 1]));
            }
        }

        return dp[n];
    }
};