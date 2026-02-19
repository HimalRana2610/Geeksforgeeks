#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxWater(vector<int> &arr)
    {
        int left = 0, right = arr.size() - 1, ans = 0;
        while (left < right)
        {
            ans = max(ans, min(arr[left], arr[right]) * (right - left));
            if (arr[left] < arr[right])
            {
                ++left;
            }
            else
            {
                --right;
            }
        }

        return ans;
    }
};