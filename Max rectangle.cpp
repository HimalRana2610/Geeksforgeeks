#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size(), ans = 0;
        vector<int> heights(m, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                heights[j] = (mat[i][j] == 1) ? heights[j] + 1 : 0;
            }

            stack<int> s;
            heights.push_back(0);

            int current = 0;
            for (int k = 0; k <= m; k++)
            {
                while (!s.empty() && heights[s.top()] > heights[k])
                {
                    int height = heights[s.top()];
                    s.pop();
                    current = max(current, height * (k - (s.empty() ? -1 : s.top()) - 1));
                }
                s.push(k);
            }

            heights.pop_back();
            ans = max(ans, current);
        }

        return ans;
    }
};