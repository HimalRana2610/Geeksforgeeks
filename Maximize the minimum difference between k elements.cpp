#include <bits/stdc++.h>
using namespace std;

bool is_possible(vector<int> &arr, int mid, int k)
{
    int cnt = 1, last = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] - last >= mid)
        {
            cnt++;
            last = arr[i];

            if (cnt == k)
            {
                return true;
            }
        }
    }

    return false;
}

class Solution
{
public:
    int maxMinDiff(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());

        int left = 0, right = arr.back() - arr[0], ans = 0;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (is_possible(arr, mid, k))
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