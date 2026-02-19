#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &mat, int x)
    {
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; i++)
        {
            if (mat[i][0] >= mat[i][m - 1])
            {
                for (int j = 0; j < m; j++)
                {
                    if (mat[i][j] == x)
                    {
                        return true;
                    }
                }
            }
            if (mat[i][0] <= x && mat[i][m - 1] >= x)
            {
                if (binary_search(mat[i].begin(), mat[i].end(), x))
                {
                    return true;
                }
            }
        }

        return false;
    }
};