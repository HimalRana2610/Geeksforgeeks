#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> find3Numbers(vector<int> &arr)
    {
        int n = arr.size();
        if (n < 3)
        {
            return {};
        }

        int first = INT_MAX, second = INT_MAX, prev = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= first)
            {
                first = arr[i];
            }
            else if (arr[i] <= second)
            {
                second = arr[i];
                prev = first;
            }
            else
            {
                return {prev, second, arr[i]};
            }
        }

        return {};
    }
};