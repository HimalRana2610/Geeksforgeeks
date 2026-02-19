#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthMissing(vector<int> &arr, int k)
    {
        int n = arr.size(), cnt = 0, current = 1, i = 0;
        while (cnt < k)
        {
            if (i < n && arr[i] == current)
            {
                i++;
            }
            else
            {
                cnt++;
                if (cnt == k)
                {
                    return current;
                }
            }
            current++;
        }

        return -1;
    }
};