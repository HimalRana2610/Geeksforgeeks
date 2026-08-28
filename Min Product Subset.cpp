#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minProd(vector<int> &arr)
    {
        int neg = 0, zero = 0, prod = 1, m = INT_MAX, ans = INT_MAX;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 0)
            {
                zero++;
                continue;
            }

            prod *= arr[i];
            if (arr[i] < 0)
            {
                neg++;
                m = min(m, abs(arr[i]));
            }
            else
            {
                ans = min(ans, arr[i]);
            }
        }

        if (neg == 0 && ans == INT_MAX)
        {
            return 0;
        }

        if (neg > 0)
        {
            if (neg % 2 == 1)
            {
                return prod;
            }
            return prod / (-m);
        }

        if (zero > 0)
        {
            return 0;
        }

        return ans;
    }
};