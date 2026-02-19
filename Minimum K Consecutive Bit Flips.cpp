#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kBitFlips(vector<int> &arr, int k)
    {
        int n = arr.size(), flip = 0, res = 0;
        vector<int> flipped(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (i >= k)
            {
                flip -= flipped[i - k];
            }
            if ((arr[i] + flip) % 2 == 0)
            {
                if (i + k > n)
                {
                    return -1;
                }

                res++;
                flip++;
                flipped[i] = 1;
            }
        }

        return res;
    }
};