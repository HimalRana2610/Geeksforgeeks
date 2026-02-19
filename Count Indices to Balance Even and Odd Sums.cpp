#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int cntWays(vector<int> &arr)
    {
        int n = arr.size(), even = 0, odd = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                even += arr[i];
            }
            else
            {
                odd += arr[i];
            }
        }

        int prefixEven = 0, prefixOdd = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                even -= arr[i];
            }
            else
            {
                odd -= arr[i];
            }

            if (prefixEven + odd == prefixOdd + even)
            {
                ans++;
            }

            if (i % 2 == 0)
            {
                prefixEven += arr[i];
            }
            else
            {
                prefixOdd += arr[i];
            }
        }

        return ans;
    }
};