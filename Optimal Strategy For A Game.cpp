#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumAmount(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for (int g = 0; g < n; g++)
        {
            for (int i = 0, j = g; j < n; i++, j++)
            {
                int l = (((i + 2) <= j) ? dp[i + 2][j] : 0), m = (((i + 1) <= (j - 1)) ? dp[i + 1][j - 1] : 0), r = ((i <= (j - 2)) ? dp[i][j - 2] : 0);
                dp[i][j] = max(arr[i] + min(l, m), arr[j] + min(m, r));
            }
        }

        return dp[0][n - 1];
    }
};