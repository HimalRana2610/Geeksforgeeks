#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        int n = mat.size(), row = -1;
        for (int i = 0; i < n; i++)
        {
            if (count(mat[i].begin(), mat[i].end(), 1) == 1)
            {
                row = i;
                break;
            }
        }

        if (row == -1)
        {
            return -1;
        }

        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (mat[i][row] == 0)
            {
                flag = false;
                break;
            }
        }

        if (!flag)
        {
            return -1;
        }

        return row;
    }
};