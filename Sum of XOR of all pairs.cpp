#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long sumXOR(vector<int> &arr)
    {
        int n = arr.size();
        long long ans = 0;

        for (int i = 0; i < 32; i++)
        {
            long long cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[j] & (1 << i))
                {
                    cnt++;
                }
            }
            ans += cnt * (n - cnt) * (1LL << i);
        }

        return ans;
    }
};