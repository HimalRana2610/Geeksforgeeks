#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &arr)
    {
        int mx = arr[0], mn = arr[0], ans = arr[0];
        for (int i = 1; i < arr.size(); ++i)
        {
            if (arr[i] < 0)
            {
                swap(mx, mn);
            }

            mx = max(arr[i], mx * arr[i]);
            mn = min(arr[i], mn * arr[i]);
            ans = max(ans, mx);
        }

        return ans;
    }
};