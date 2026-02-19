#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubarraySum(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<long long> prefix(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] + arr[i - 1];
        }

        long long ans = LLONG_MIN;
        for (int i = k; i <= n; i++)
        {
            ans = max(ans, prefix[i] - prefix[i - k]);
        }

        return ans;
    }
};