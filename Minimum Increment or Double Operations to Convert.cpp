#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countMinOperations(vector<int> &arr)
    {
        int inc = 0, m = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            int l = 0;
            while (arr[i] > 0)
            {
                if (arr[i] & 1)
                {
                    inc++;
                }

                l++;
                arr[i] >>= 1;
            }

            m = max(m, l);
        }

        int dbl = max(0, m - 1);
        return inc + dbl;
    }
};