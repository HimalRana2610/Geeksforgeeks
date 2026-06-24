#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCoverage(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            bool flag = false;
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                {
                    flag = true;
                }
                else
                {
                    if (flag)
                    {
                        ans++;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            bool flag = false;
            for (int j = m - 1; j >= 0; j--)
            {
                if (mat[i][j] == 1)
                {
                    flag = true;
                }
                else
                {
                    if (flag)
                    {
                        ans++;
                    }
                }
            }
        }

        for (int j = 0; j < m; j++)
        {
            bool flag = false;
            for (int i = 0; i < n; i++)
            {
                if (mat[i][j] == 1)
                {
                    flag = true;
                }
                else
                {
                    if (flag)
                    {
                        ans++;
                    }
                }
            }
        }

        for (int j = 0; j < m; j++)
        {
            bool flag = false;
            for (int i = n - 1; i >= 0; i--)
            {
                if (mat[i][j] == 1)
                {
                    flag = true;
                }
                else
                {
                    if (flag)
                    {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};