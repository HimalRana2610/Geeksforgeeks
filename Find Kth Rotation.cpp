#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKRotation(vector<int> &arr)
    {
        int n = arr.size(), first = arr[0];
        sort(arr.begin(), arr.end());

        if (arr[0] == first)
        {
            return 0;
        }

        for (int i = 1; i < n; ++i)
        {
            if (arr[i] == first)
            {
                return n - i;
            }
        }
    }
};