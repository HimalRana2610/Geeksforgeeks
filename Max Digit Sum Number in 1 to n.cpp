#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMax(int n)
    {
        string s = to_string(n);
        int l = s.length(), sum = 0;

        for (int i = 0; i < l; i++)
        {
            sum += s[i] - '0';
        }

        int ans = n, best = sum, suffix = 0;
        long long p = 1;

        for (int i = l - 1; i >= 0; i--)
        {
            int digit = s[i] - '0';
            suffix += digit;

            if (digit > 0)
            {
                long long candidate = (n / (p * 10)) * (p * 10) + (digit - 1) * p + p - 1;
                int r = l - i - 1, current = sum - suffix + (digit - 1) + 9 * r;

                if (current > best || (current == best && candidate > ans))
                {
                    best = current;
                    ans = (int)candidate;
                }
            }

            p *= 10;
        }

        return ans;
    }
};