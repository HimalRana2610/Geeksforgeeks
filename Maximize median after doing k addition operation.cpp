#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool is_valid(vector<int> &arr, int mid, int k)
    {
        int n = arr.size();
        if (n % 2 == 0)
        {
            if (arr[n / 2] <= mid)
            {
                k -= (2 * mid - arr[n / 2] - arr[n / 2 - 1]);
            }
            else
            {
                k -= (2 * mid - (arr[n / 2] + arr[n / 2 - 1]));
            }

            for (int i = n / 2 + 1; i < n; i++)
            {
                if (arr[i] < mid)
                {
                    k -= mid - arr[i];
                }
            }
        }
        else
        {
            for (int i = n / 2; i < n; i++)
            {
                if (arr[i] < mid)
                {
                    k -= mid - arr[i];
                }
            }
        }

        return k >= 0;
    }

    int maximizeMedian(vector<int> &arr, int k)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int median = (n % 2 == 0) ? ((arr[n / 2] + arr[n / 2 - 1]) / 2) : arr[n / 2];
        int left = median, right = median + k, ans = median;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (is_valid(arr, mid, k))
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return ans;
    }
};