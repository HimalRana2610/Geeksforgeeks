#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findSmallest(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int ans = 1;

        for (int i = 0; i < arr.size() && arr[i] <= ans; i++)
        {
            ans += arr[i];
        }

        return ans;
    }
};