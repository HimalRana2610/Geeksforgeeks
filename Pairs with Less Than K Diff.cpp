#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPairs(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());

        int ans = 0, j = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            while (arr[i] - arr[j] >= k)
            {
                j++;
            }
            ans += (i - j);
        }

        return ans;
    }
};