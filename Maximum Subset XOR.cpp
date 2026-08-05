#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubsetXOR(vector<int> &arr)
    {
        int n = arr.size(), idx = 0;
        for (int i = 31; i >= 0; i--)
        {
            int mi = idx, m = INT_MIN;
            for (int j = idx; j < n; j++)
            {
                if ((arr[j] & (1 << i)) != 0 && arr[j] > m)
                {
                    m = arr[j];
                    mi = j;
                }
            }

            if (m == INT_MIN)
            {
                continue;
            }

            swap(arr[idx], arr[mi]);

            for (int j = 0; j < n; j++)
            {
                if (j != idx && (arr[j] & (1 << i)) != 0)
                {
                    arr[j] ^= arr[idx];
                }
            }

            idx++;
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans ^= arr[i];
        }

        return ans;
    }
};