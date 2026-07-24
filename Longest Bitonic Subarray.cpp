#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bitonic(vector<int> &arr)
    {
        int n = arr.size(), ans = 1, start = 0, next = 0;
        for (int i = 0; i < n - 1;)
        {
            while (i < n - 1 && arr[i] <= arr[i + 1])
            {
                i++;
            }
            while (i < n - 1 && arr[i] >= arr[i + 1])
            {
                if (i < n - 1 && arr[i] > arr[i + 1])
                {
                    next = i + 1;
                }
                i++;
            }

            ans = max(ans, i - start + 1);
            start = next;
        }

        return ans;
    }
};