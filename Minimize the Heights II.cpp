#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMinDiff(vector<int> &arr, int k)
    {
        int n = arr.size();
        if (n == 1)
        {
            return 0;
        }

        sort(arr.begin(), arr.end());
        int ans = arr[n - 1] - arr[0], smallest = arr[0] + k, largest = arr[n - 1] - k;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] < k)
            {
                continue;
            }

            ans = min(ans, max(largest, arr[i - 1] + k) - min(smallest, arr[i] - k));
        }

        return ans;
    }
};