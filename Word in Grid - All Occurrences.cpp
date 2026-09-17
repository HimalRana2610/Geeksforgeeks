#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool search2D(vector<vector<char>> grid, int row, int col, string word)
    {
        if (grid[row][col] != word[0])
        {
            return false;
        }

        int n = grid.size(), m = grid[0].size(), l = word.size();
        vector<pair<int, int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        for (int d = 0; d < 8; d++)
        {
            int k, x = row + dirs[d].first, y = col + dirs[d].second;
            for (k = 1; k < l; k++)
            {
                if (x >= n || x < 0 || y >= m || y < 0)
                {
                    break;
                }

                if (grid[x][y] != word[k])
                {
                    break;
                }

                x += dirs[d].first, y += dirs[d].second;
            }

            if (k == l)
            {
                return true;
            }
        }

        return false;
    }

    vector<vector<int>> searchWord(vector<vector<char>> &mat, string &word)
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (search2D(mat, i, j, word))
                {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};