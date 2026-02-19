#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool is_valid(vector<int> &arr, int n, int k, int mid)
    {
        int cnt = 1, sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > mid)
            {
                return false;
            }

            if (sum + arr[i] > mid)
            {
                cnt++;
                sum = arr[i];

                if (cnt > k)
                {
                    return false;
                }
            }
            else
            {
                sum += arr[i];
            }
        }

        return true;
    }

    int findPages(vector<int> &arr, int k)
    {
        if (arr.size() < k)
        {
            return -1;
        }

        int low = *max_element(arr.begin(), arr.end()), high = accumulate(arr.begin(), arr.end(), 0), ans = accumulate(arr.begin(), arr.end(), 0);
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (is_valid(arr, arr.size(), k, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};