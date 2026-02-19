#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxRemove(vector<vector<int>> &stones)
    {
        int n = stones.size();
        unordered_map<int, vector<int>> rowMap, colMap;

        for (int i = 0; i < n; i++)
        {
            rowMap[stones[i][0]].push_back(i);
            colMap[stones[i][1]].push_back(i);
        }

        vector<bool> visited(n, false);
        int components = 0;

        function<void(int)> dfs = [&](int stoneIdx)
        {
            visited[stoneIdx] = true;
            int row = stones[stoneIdx][0], col = stones[stoneIdx][1];

            for (int neighbor : rowMap[row])
            {
                if (!visited[neighbor])
                {
                    dfs(neighbor);
                }
            }
            for (int neighbor : colMap[col])
            {
                if (!visited[neighbor])
                {
                    dfs(neighbor);
                }
            }
        };

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                components++;
                dfs(i);
            }
        }

        return n - components;
    }
};