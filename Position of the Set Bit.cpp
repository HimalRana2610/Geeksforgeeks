#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPosition(int n)
    {
        if (__builtin_popcount(n) != 1)
        {
            return -1;
        }

        return log2(n) + 1;
    }
};