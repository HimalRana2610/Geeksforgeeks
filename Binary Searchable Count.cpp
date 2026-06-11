#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &arr, int l, int r, int lr, int rl)
    {
        if (l > r)
        {
            return 0;
        }

        int m = l + (r - l) / 2;
        return solve(arr, l, m - 1, lr, min(rl, arr[m])) + solve(arr, m + 1, r, max(lr, arr[m]), rl) + (arr[m] > lr && arr[m] < rl);
    }

    int binarySearchable(vector<int> &arr)
    {
        int n = arr.size();
        return solve(arr, 0, n - 1, INT_MIN, INT_MAX);
    }
};