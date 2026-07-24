#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxAmount(vector<int> &arr, int k)
    {
        int n = arr.size(), m = *max_element(arr.begin(), arr.end()), low = 0, high = m;
        while (low < high)
        {
            int mid = (low + high) / 2;
            long long cnt = 0;

            for (int i = 0; i < n; i++)
            {
                if (arr[i] > mid)
                {
                    cnt += (arr[i] - mid);
                }
            }

            if (cnt > k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }

        int level = low;
        long long sold = 0, ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > level)
            {
                long long tickets = arr[i] - level;
                sold += tickets;

                ans += (1LL * (arr[i] + level + 1) * tickets) / 2;
                ans %= 1000000007;
            }
        }

        ans = (ans + 1LL * (k - sold) * level) % 1000000007;
        return ans;
    }
};