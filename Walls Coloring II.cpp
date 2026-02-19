#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(vector<vector<int>> &costs)
    {
        int n = costs.size();
        if (n == 0)
        {
            return 0;
        }

        int k = costs[0].size();
        if (k == 0)
        {
            return 0;
        }

        if (k == 1 && n > 1)
        {
            return -1;
        }

        vector<int> prev(k), curr(k);
        for (int j = 0; j < k; j++)
        {
            prev[j] = costs[0][j];
        }

        for (int i = 1; i < n; i++)
        {
            int m1 = INT_MAX, m2 = INT_MAX, m = -1;
            for (int j = 0; j < k; j++)
            {
                if (prev[j] < m1)
                {
                    m2 = m1;
                    m1 = prev[j];
                    m = j;
                }
                else if (prev[j] < m2)
                {
                    m2 = prev[j];
                }
            }

            for (int j = 0; j < k; j++)
            {
                if (j != m)
                {
                    curr[j] = m1 + costs[i][j];
                }
                else
                {
                    curr[j] = m2 + costs[i][j];
                }
            }

            swap(prev, curr);
        }

        return *min_element(prev.begin(), prev.end());
    }
};