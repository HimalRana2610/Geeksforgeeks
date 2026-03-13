#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSquare(vector<vector<int>> &mat, int x)
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> rowPrefix = mat;

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                rowPrefix[i][j] += rowPrefix[i][j - 1];
            }
        }

        int mx = min(n, m), ans = 0;
        for (int l = 1; l <= mx; l++)
        {
            for (int i = 0; i <= m - l; i++)
            {
                int j = i + l - 1, sum = 0;
                for (int row = 0; row < l - 1; row++)
                {
                    sum += rowPrefix[row][j] - (i > 0 ? rowPrefix[row][i - 1] : 0);
                }

                for (int row = l - 1; row < n; row++)
                {
                    sum += rowPrefix[row][j] - (i > 0 ? rowPrefix[row][i - 1] : 0);
                    if (sum == x)
                    {
                        ans++;
                    }
                    sum -= rowPrefix[row - l + 1][j] - (i > 0 ? rowPrefix[row - l + 1][i - 1] : 0);
                }
            }
        }

        return ans;
    }
};