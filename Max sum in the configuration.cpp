#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSum(vector<int> &arr)
    {
        int n = arr.size();
        long long sum = 0, current = 0;

        for (int i = 0; i < n; ++i)
        {
            sum += arr[i];
            current += static_cast<long long>(i) * arr[i];
        }

        long long ans = current;
        for (int i = 1; i < n; ++i)
        {
            current = current - sum + static_cast<long long>(n) * arr[i - 1];
            ans = max(ans, current);
        }

        return static_cast<int>(ans);
    }
};