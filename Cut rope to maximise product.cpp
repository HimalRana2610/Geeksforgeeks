#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int power(int base, int exp)
    {
        int ans = 1;
        while (exp)
        {
            if (exp & 1)
            {
                ans *= base;
            }

            base *= base;
            exp >>= 1;
        }

        return ans;
    }

    int maxProduct(int n)
    {
        if (n <= 3)
        {
            return n - 1;
        }

        int three = n / 3, r = n % 3;
        if (r == 1)
        {
            three--;
            r = 4;
        }

        int ans = power(3, three);
        if (r == 2 || r == 4)
        {
            ans *= r;
        }

        return ans;
    }
};