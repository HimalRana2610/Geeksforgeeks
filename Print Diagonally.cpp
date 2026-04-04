#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> diagView(vector<vector<int>> mat)
    {
        int n = mat.size();
        vector<int> ans;

        for (int k = 0; k < n; k++)
        {
            for (int i = 0, j = k; i < n && j >= 0; i++, j--)
            {
                ans.push_back(mat[i][j]);
            }
        }

        for (int k = 1; k < n; k++)
        {
            for (int i = k, j = n - 1; i < n && j >= 0; i++, j--)
            {
                ans.push_back(mat[i][j]);
            }
        }

        return ans;
    }
};