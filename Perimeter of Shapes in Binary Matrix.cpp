#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPerimeter(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size(), ans = 0;
        vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                {
                    ans += 4;
                    for (int d = 0; d < 4; d++)
                    {
                        int ni = i + dirs[d].first, nj = j + dirs[d].second;
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m && mat[ni][nj] == 1)
                        {
                            ans--;
                        }
                    }
                }
            }
        }

        return ans;
    }
};