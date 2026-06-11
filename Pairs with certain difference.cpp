#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumDiffPairs(vector<int> &arr, int k)
    {
        sort(arr.rbegin(), arr.rend());

        int ans = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i - 1] - arr[i] < k)
            {
                ans += arr[i - 1] + arr[i++];
            }
        }

        return ans;
    }
};