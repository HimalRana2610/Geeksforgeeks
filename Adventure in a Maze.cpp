#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findWays(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> next_ways(n, 0), next_m(n, -1);

        for (int i = n - 1; i >= 0; i--)
        {
            vector<int> current_ways(n, 0), current_m(n, -1);
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == n - 1 && j == n - 1)
                {
                    current_ways[j] = 1;
                    current_m[j] = grid[i][j];
                    continue;
                }

                int m = -1;
                long long ways = 0;

                if (grid[i][j] == 1 || grid[i][j] == 3)
                {
                    if (j + 1 < n && current_m[j + 1] != -1)
                    {
                        ways = (ways + current_ways[j + 1]) % 1000000007;
                        m = max(m, grid[i][j] + current_m[j + 1]);
                    }
                }

                if (grid[i][j] == 2 || grid[i][j] == 3)
                {
                    if (i + 1 < n && next_m[j] != -1)
                    {
                        ways = (ways + next_ways[j]) % 1000000007;
                        m = max(m, grid[i][j] + next_m[j]);
                    }
                }

                current_ways[j] = ways;
                current_m[j] = m;
            }

            next_ways = move(current_ways);
            next_m = move(current_m);
        }

        return {next_ways[0], (next_m[0] == -1) ? 0 : next_m[0]};
    }
};