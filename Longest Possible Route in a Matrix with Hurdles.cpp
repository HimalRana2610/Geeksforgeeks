#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(vector<vector<int>> &mat, int i, int j, int x, int y)
    {
        int n = mat.size(), m = mat[0].size();
        if (i == x && j == y)
        {
            return 0;
        }
        if (i < 0 || i >= n || j < 0 || j >= m || mat[i][j] == 0)
        {
            return -1;
        }

        mat[i][j] = 0;
        int ans = -1;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int k = 0; k < directions.size(); k++)
        {
            int ni = i + directions[k].first, nj = j + directions[k].second;
            int current = dfs(mat, ni, nj, x, y);

            if (current != -1)
            {
                ans = max(ans, current + 1);
            }
        }

        mat[i][j] = 1;
        return ans;
    }

    int longestPath(vector<vector<int>> &mat, int xs, int ys, int xd, int yd)
    {
        if (mat[xs][ys] == 0 || mat[xd][yd] == 0)
        {
            return -1;
        }

        return dfs(mat, xs, ys, xd, yd);
    }
};