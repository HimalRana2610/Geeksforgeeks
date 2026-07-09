#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSumSubarray(vector<int> &arr)
    {
        int n = arr.size(), not_used = arr[0], used = 0, ans = arr[0];
        for (int i = 1; i < n; i++)
        {
            used = max(not_used, arr[i] + used);
            not_used = max(arr[i], arr[i] + not_used);
            ans = max(ans, max(not_used, used));
        }

        return ans;
    }
};