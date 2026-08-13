#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> largestSquare(vector<vector<int>> &mat, vector<vector<int>> &queries, int k)
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                prefix[i + 1][j + 1] = prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j] + mat[i][j];
            }
        }

        vector<int> ans;
        for (auto &q : queries)
        {
            int i = q[0], j = q[1];
            int dist = min({i, j, n - i - 1, m - j - 1});

            if (mat[i][j] > k)
            {
                ans.push_back(-1);
                continue;
            }

            int low = 0, high = dist, best = 0;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (prefix[i + mid + 1][j + mid + 1] - prefix[i - mid][j + mid + 1] - prefix[i + mid + 1][j - mid] + prefix[i - mid][j - mid] <= k)
                {
                    best = mid;
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }

            ans.push_back(2 * best + 1);
        }

        return ans;
    }
};