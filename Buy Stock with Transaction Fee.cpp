#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &arr, int k)
    {
        int n = arr.size();
        if (n == 1)
        {
            return 0;
        }

        int hold = -arr[0], nothold = 0;
        for (int i = 1; i < n; ++i)
        {
            int newHold = max(hold, nothold - arr[i]), newNothold = max(nothold, hold + arr[i] - k);
            hold = newHold;
            nothold = newNothold;
        }

        return nothold;
    }
};