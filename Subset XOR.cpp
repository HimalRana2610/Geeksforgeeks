#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> subsetXOR(int n)
    {
        vector<int> res;
        int xorVal = 0;

        for (int i = 1; i < n; i++)
        {
            xorVal ^= i;
        }

        if (xorVal == n)
        {
            for (int i = 1; i < n; i++)
            {
                res.push_back(i);
            }
            return res;
        }

        xorVal ^= n;
        int exclude = xorVal ^ n;

        for (int i = 1; i <= n; i++)
        {
            if (i != exclude)
            {
                res.push_back(i);
            }
        }

        return res;
    }
};