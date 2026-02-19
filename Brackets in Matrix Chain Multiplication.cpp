#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string backtrack(int i, int j, vector<vector<int>> &split)
    {
        if (i == j)
        {
            return string(1, 'A' + i);
        }

        int k = split[i][j];
        return "(" + backtrack(i, k, split) + backtrack(k + 1, j, split) + ")";
    }

    string matrixChainOrder(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<long long>> dp(n, vector<long long>(n, 0));
        vector<vector<int>> split(n, vector<int>(n, 0));

        for (int l = 2; l < n; l++)
        {
            for (int i = 0; i < n - l; i++)
            {
                int j = i + l - 1;
                dp[i][j] = LLONG_MAX;

                for (int k = i; k < j; k++)
                {
                    long long cost = dp[i][k] + dp[k + 1][j] + (long long)arr[i] * arr[k + 1] * arr[j + 1];
                    if (cost < dp[i][j])
                    {
                        dp[i][j] = cost;
                        split[i][j] = k;
                    }
                }
            }
        }

        return backtrack(0, n - 2, split);
    }
};