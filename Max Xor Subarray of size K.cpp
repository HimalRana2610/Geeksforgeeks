#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubarrayXOR(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] ^ arr[i - 1];
        }

        int ans = INT_MIN;
        for (int i = k; i <= n; i++)
        {
            ans = max(ans, prefix[i] ^ prefix[i - k]);
        }

        return ans;
    }
};