#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findWays(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> suffix(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                suffix[i][j] = suffix[i + 1][j] + suffix[i][j + 1] - suffix[i + 1][j + 1] + matrix[i][j];
            }
        }

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, 0)));
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < m; c++)
            {
                dp[r][c][1] = suffix[r][c] > 0 ? 1 : 0;
            }
        }

        for (int p = 2; p <= k; p++)
        {
            vector<vector<int>> suffix_row(n + 1, vector<int>(m, 0));
            for (int c = 0; c < m; c++)
            {
                for (int r = n - 1; r >= 0; r--)
                {
                    suffix_row[r][c] = (suffix_row[r + 1][c] + dp[r][c][p - 1]) % 1000000007;
                }
            }

            vector<vector<int>> suffix_col(n, vector<int>(m + 1, 0));
            for (int r = 0; r < n; r++)
            {
                for (int c = m - 1; c >= 0; c--)
                {
                    suffix_col[r][c] = (suffix_col[r][c + 1] + dp[r][c][p - 1]) % 1000000007;
                }
            }

            for (int r = n - 1; r >= 0; r--)
            {
                for (int c = m - 1; c >= 0; c--)
                {
                    if (suffix[r][c] == 0)
                    {
                        continue;
                    }

                    int low = r + 1, high = n, ans = 0;
                    while (low < high)
                    {
                        int mid = (low + high) / 2;
                        if (suffix[mid][c] < suffix[r][c])
                        {
                            high = mid;
                        }
                        else
                        {
                            low = mid + 1;
                        }
                    }

                    if (low < n)
                    {
                        ans = (ans + suffix_row[low][c]) % 1000000007;
                    }

                    low = c + 1;
                    high = m;

                    while (low < high)
                    {
                        int mid = (low + high) / 2;
                        if (suffix[r][mid] < suffix[r][c])
                        {
                            high = mid;
                        }
                        else
                        {
                            low = mid + 1;
                        }
                    }

                    if (low < m)
                    {
                        ans = (ans + suffix_col[r][low]) % 1000000007;
                    }

                    dp[r][c][p] = ans;
                }
            }
        }

        return dp[0][0][k];
    }
};