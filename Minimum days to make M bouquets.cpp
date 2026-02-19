#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool is_possible(vector<int> &arr, int k, int m, int mid)
    {
        int count = 0, flowers = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] <= mid)
            {
                flowers++;
                if (flowers == k)
                {
                    count++;
                    flowers = 0;
                }
            }
            else
            {
                flowers = 0;
            }
        }

        return count >= m;
    }

    int minDaysBloom(vector<int> &arr, int k, int m)
    {
        if (m * k > arr.size())
        {
            return -1;
        }

        int left = *min_element(arr.begin(), arr.end()), right = *max_element(arr.begin(), arr.end()), ans = *max_element(arr.begin(), arr.end());
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (is_possible(arr, k, m, mid))
            {
                ans = mid;
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return ans;
    }
};