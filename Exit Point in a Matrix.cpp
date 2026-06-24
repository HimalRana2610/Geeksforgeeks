#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> exitPoint(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size(), d = 0;
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        pair<int, int> current = {0, 0};

        while (true)
        {
            int x = current.first, y = current.second;
            if (mat[x][y] == 1)
            {
                d = (d + 1) % 4;
                mat[x][y] = 0;
            }

            int nx = x + dirs[d].first, ny = y + dirs[d].second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                current = {nx, ny};
                continue;
            }

            return {x, y};
        }

        return {};
    }
};