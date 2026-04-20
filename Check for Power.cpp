#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPower(int x, int y)
    {
        if (y == 1)
        {
            return x != 0;
        }

        if (x == 1)
        {
            return y == 1;
        }

        if (x < 0 || y < 0)
        {
            return false;
        }

        while (y % x == 0)
        {
            y /= x;
        }

        return y == 1;
    }
};