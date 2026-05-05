#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwaps(vector<int> &arr)
    {
        int n = arr.size(), one = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 1)
            {
                one++;
            }
        }

        if (one == 0)
        {
            return -1;
        }

        if (one == n)
        {
            return 0;
        }

        int m = 0, current = 0;
        for (int i = 0; i < one; i++)
        {
            if (arr[i] == 1)
            {
                current++;
            }
        }

        m = current;
        for (int i = one; i < n; i++)
        {
            if (arr[i] == 1)
            {
                current++;
            }
            if (arr[i - one] == 1)
            {
                current--;
            }

            m = max(m, current);
        }

        return one - m;
    }
};