#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smaller(vector<int> &arr, int r)
    {
        int n = arr.size(), ans = 0;
        for (int i = 0; i < n - 2; i++)
        {
            int left = i + 1, right = n - 1;
            while (left < right)
            {
                if (arr[i] + arr[left] + arr[right] <= r)
                {
                    ans += right - left++;
                }
                else
                {
                    right--;
                }
            }
        }

        return ans;
    }

    int countTriplets(vector<int> &arr, int l, int r)
    {
        sort(arr.begin(), arr.end());
        return smaller(arr, r) - smaller(arr, l - 1);
    }
};