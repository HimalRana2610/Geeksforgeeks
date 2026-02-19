#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries)
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                prefix[i][j] = mat[i - 1][j - 1] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }

        int q = queries.size();
        vector<int> ans(q);

        for (int i = 0; i < q; i++)
        {
            int r1 = queries[i][0] + 1, c1 = queries[i][1] + 1, r2 = queries[i][2] + 1, c2 = queries[i][3] + 1;
            ans[i] = prefix[r2][c2] - prefix[r1 - 1][c2] - prefix[r2][c1 - 1] + prefix[r1 - 1][c1 - 1];
        }

        return ans;
    }
};