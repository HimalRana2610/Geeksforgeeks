#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFruits(vector<int> &arr, int m)
    {
        int n = arr.size();
        if (m > n)
        {
            return accumulate(arr.begin(), arr.end(), 0LL);
        }

        for (int i = 0; i < m - 1; i++)
        {
            arr.push_back(arr[i]);
        }

        vector<long long> prefix(n + m, 0);
        for (int i = 0; i < n + m - 1; i++)
        {
            prefix[i + 1] = prefix[i] + arr[i];
        }

        long long ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, prefix[i + m] - prefix[i]);
        }

        return ans;
    }
};