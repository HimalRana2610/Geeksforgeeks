#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMoves(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> lcs(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            if (lcs[arr[i] - 1] != 0)
            {
                lcs[arr[i]] = lcs[arr[i] - 1] + 1;
            }
            else
            {
                lcs[arr[i]] = 1;
            }
        }

        return n - *max_element(lcs.begin(), lcs.end());
    }
};