#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxOnes(vector<int> &arr, int k)
    {
        int left = 0, right = 0, ans = 0, zero = 0;
        while (right < arr.size())
        {
            if (arr[right] == 0)
                zero++;

            while (zero > k)
            {
                if (arr[left] == 0)
                    zero--;
                left++;
            }

            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};