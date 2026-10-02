#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int formPyramid(vector<int> &arr)
    {
        int n = arr.size(), total = 0;
        for (int i = 0; i < n; i++)
        {
            total += arr[i];
        }

        if (n <= 2)
        {
            return total - 1;
        }

        vector<int> left(n);
        left[0] = 1;

        for (int i = 1; i < n; i++)
        {
            left[i] = min(left[i - 1] + 1, arr[i]);
        }

        vector<int> right(n);
        right[n - 1] = 1;

        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = min(right[i + 1] + 1, arr[i]);
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, total - (min(left[i], right[i]) * min(left[i], right[i])));
        }

        return ans;
    }
};