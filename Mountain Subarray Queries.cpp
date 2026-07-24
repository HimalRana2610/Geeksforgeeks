#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        int n = arr.size();
        vector<int> dec(n);
        dec[n - 1] = n - 1;

        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] <= arr[i + 1])
            {
                dec[i] = dec[i + 1];
            }
            else
            {
                dec[i] = i;
            }
        }

        vector<int> inc(n);
        inc[0] = 0;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] <= arr[i - 1])
            {
                inc[i] = inc[i - 1];
            }
            else
            {
                inc[i] = i;
            }
        }

        vector<bool> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            ans.push_back(dec[queries[i][0]] >= inc[queries[i][1]]);
        }

        return ans;
    }
};