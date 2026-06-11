#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxProduct(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 1)
        {
            return arr[0];
        }

        int zero = 0, neg = 0, m = INT_MIN, idx = -1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                zero++;
            }
            else if (arr[i] < 0)
            {
                neg++;
                if (idx == -1 || arr[i] > m)
                {
                    m = arr[i];
                    idx = i;
                }
            }
        }

        if ((zero == n) || (neg == 1 && zero == n - 1))
        {
            return 0;
        }

        long long ans = 1;
        for (int i = 0; i < n; i++)
        {
            if ((arr[i] == 0) || (neg % 2 == 1 && i == idx))
            {
                continue;
            }

            ans = ((ans * arr[i]) % 1000000007 + 1000000007) % 1000000007;
        }

        return ans;
    }
};