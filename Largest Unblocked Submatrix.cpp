#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestArea(int n, int m, vector<vector<int>> &arr)
    {
        vector<int> rows, cols;
        rows.push_back(0);
        rows.push_back(n + 1);
        cols.push_back(0);
        cols.push_back(m + 1);

        for (int i = 0; i < arr.size(); i++)
        {
            rows.push_back(arr[i][0]);
            cols.push_back(arr[i][1]);
        }

        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());

        int mr = 0, mc = 0;
        for (int i = 1; i < rows.size(); i++)
        {
            mr = max(mr, rows[i] - rows[i - 1] - 1);
        }
        for (int i = 1; i < cols.size(); i++)
        {
            mc = max(mc, cols[i] - cols[i - 1] - 1);
        }

        return mr * mc;
    }
};