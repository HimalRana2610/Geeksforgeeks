#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumSum(vector<vector<int>> &mat, int k)
    {
        int n = mat.size();
        vector<vector<int>> prefix(n, vector<int>(n, 0));
        prefix[0][0] = mat[0][0];

        for (int i = 1; i < n; i++)
        {
            prefix[i][0] = prefix[i - 1][0] + mat[i][0];
        }
        for (int j = 1; j < n; j++)
        {
            prefix[0][j] = prefix[0][j - 1] + mat[0][j];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                prefix[i][j] = mat[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }

        int ans = INT_MIN;
        for (int i = k - 1; i < n; i++)
        {
            for (int j = k - 1; j < n; j++)
            {
                int sum = prefix[i][j];
                if (i >= k)
                {
                    sum -= prefix[i - k][j];
                }
                if (j >= k)
                {
                    sum -= prefix[i][j - k];
                }
                if (i >= k && j >= k)
                {
                    sum += prefix[i - k][j - k];
                }

                ans = max(ans, sum);
            }
        }

        return ans;
    }
};