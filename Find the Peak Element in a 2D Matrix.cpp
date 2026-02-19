#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int ans = INT_MIN;
        for (int i = 0; i < mat.size(); i++)
        {
            ans = max(ans, *max_element(mat[i].begin(), mat[i].end()));
        }

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == ans)
                {
                    return {i, j};
                }
            }
        }

        return {-1, -1};
    }
};