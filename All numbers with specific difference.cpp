#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool is_greater(int num, int d)
    {
        int sum = 0, temp = num;
        while (temp > 0)
        {
            sum += temp % 10;
            temp /= 10;
        }

        return num - sum >= d;
    }

    int getCount(int n, int d)
    {
        int m = n + 1, left = 1, right = n;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (is_greater(mid, d))
            {
                m = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return n + 1 - m;
    }
};