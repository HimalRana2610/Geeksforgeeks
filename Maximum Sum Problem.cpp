#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSum(int n)
    {
        if (n <= 11)
        {
            return n;
        }

        return max(n / 2, maxSum(n / 2)) + max(n / 3, maxSum(n / 3)) + max(n / 4, maxSum(n / 4));
    }
};