#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int numOfWays(int n, int m)
    {
        int ans = (n * m - 1) * n * m;
        if(n >= 1 && m >= 2)
        {
            ans -= (4 * (n - 1) * (m - 2));
        }
        if(n >= 2 && m >= 1)
        {
            ans -= (4 * (n - 2) * (m - 1));
        }

        return ans;
    }
};