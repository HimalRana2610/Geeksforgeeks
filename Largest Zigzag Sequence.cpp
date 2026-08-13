#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int zigzagSequence(vector<vector<int>> &mat)
    {
        int n = mat.size();
        vector<int> prev = mat[0];

        for (int i = 1; i < n; i++)
        {
            int m1 = -1, m2 = -1, m = -1;
            for (int j = 0; j < n; j++)
            {
                if (prev[j] > m1)
                {
                    m2 = m1;
                    m1 = prev[j];
                    m = j;
                }
                else if (prev[j] > m2)
                {
                    m2 = prev[j];
                }
            }

            vector<int> current(n);
            for (int j = 0; j < n; j++)
            {
                current[j] = mat[i][j] + (j == m ? m2 : m1);
            }
            prev = current;
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, prev[i]);
        }

        return ans;
    }
};