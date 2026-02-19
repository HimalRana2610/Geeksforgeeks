#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubset(vector<int> &arr, int k)
    {
        int mid = arr.size() / 2;
        vector<long long> left(arr.begin(), arr.begin() + mid), right(arr.begin() + mid, arr.end()), sumL, sumR;

        for (int mask = 0; mask < (1 << left.size()); mask++)
        {
            long long s = 0;
            for (int i = 0; i < left.size(); i++)
            {
                if (mask & (1 << i))
                {
                    s += left[i];
                }
            }
            sumL.push_back(s);
        }

        for (int mask = 0; mask < (1 << right.size()); mask++)
        {
            long long s = 0;
            for (int i = 0; i < right.size(); i++)
            {
                if (mask & (1 << i))
                {
                    s += right[i];
                }
            }
            sumR.push_back(s);
        }

        sort(sumR.begin(), sumR.end());

        long long ans = 0;
        for (long long s : sumL)
        {
            long long target = k - s;
            ans += upper_bound(sumR.begin(), sumR.end(), target) - lower_bound(sumR.begin(), sumR.end(), target);
        }

        return ans;
    }
};