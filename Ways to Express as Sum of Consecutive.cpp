#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getCount(int n)
    {
        int ans = 0;
        for (long long i = 2;; i++)
        {
            long long sum = (i * (i - 1)) / 2;
            if (sum >= n)
            {
                break;
            }
            if ((n - sum) % i == 0)
            {
                ans++;
            }
        }

        return ans;
    }
};