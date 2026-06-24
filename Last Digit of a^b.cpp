#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int modulo(int d, string &b)
    {
        int mod = 0;
        for (int i = 0; i < b.length(); i++)
        {
            mod = (mod * 10 + b[i] - '0') % d;
        }

        return mod;
    }

    int getLastDigit(string &a, string &b)
    {
        int n = a.length(), m = b.length();
        if (m == 1 && b[0] == '0')
        {
            return 1;
        }

        if (n == 1 && a[0] == '0')
        {
            return 0;
        }

        int exp = (modulo(4, b) == 0) ? 4 : modulo(4, b);
        int ans = pow(a[n - 1] - '0', exp);

        return ans % 10;
    }
};