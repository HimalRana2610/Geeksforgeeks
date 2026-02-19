#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool is_possible(vector<int> &arr, int time, int k)
    {
        int sum = 0, p = 1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (sum + arr[i] > time)
            {
                p++;
                sum = arr[i];
            }
            else
            {
                sum += arr[i];
            }
        }

        return p <= k;
    }

    int minTime(vector<int> &arr, int k)
    {
        int left = *max_element(arr.begin(), arr.end()), right = accumulate(arr.begin(), arr.end(), 0), ans = right;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (is_possible(arr, mid, k))
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return ans;
    }
};