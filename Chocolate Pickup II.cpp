#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(int r1, int c1, int c2, int n, vector<vector<int>> &mat, vector<vector<vector<int>>> &dp)
    {
        int r2 = r1 + c1 - c2;
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || mat[r1][c1] == -1 || mat[r2][c2] == -1)
        {
            return INT_MIN;
        }

        if (r1 == n - 1 && c1 == n - 1)
        {
            return mat[r1][c1];
        }

        if (dp[r1][c1][c2] != -1)
        {
            return dp[r1][c1][c2];
        }

        int current = mat[r1][c1];
        if (r1 != r2 || c1 != c2)
        {
            current += mat[r2][c2];
        }

        current += max({dfs(r1 + 1, c1, c2 + 1, n, mat, dp), dfs(r1, c1 + 1, c2, n, mat, dp), dfs(r1 + 1, c1, c2, n, mat, dp), dfs(r1, c1 + 1, c2 + 1, n, mat, dp)});
        return dp[r1][c1][c2] = current;
    }

    int chocolatePickup(vector<vector<int>> &mat)
    {
        int n = mat.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));

        return max(0, dfs(0, 0, 0, n, mat, dp));
    }
};