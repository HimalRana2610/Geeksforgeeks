#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dominantPairs(vector<int> &arr)
    {
        int n = arr.size(), ans = 0;
        sort(arr.begin(), arr.begin() + n / 2);

        for (int i = n / 2; i < n; i++)
        {
            ans += n / 2 - (upper_bound(arr.begin(), arr.begin() + n / 2, arr[i] * 5 - 1) - arr.begin());
        }

        return ans;
    }
};