#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDeletions(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> tails;

        for (int i = 0; i < n; i++)
        {
            int low = 0, high = tails.size();
            while (low < high)
            {
                int mid = (low + high) / 2;
                if (tails[mid] < arr[i])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid;
                }
            }

            if (low == tails.size())
            {
                tails.push_back(arr[i]);
            }

            else
            {
                tails[low] = arr[i];
            }
        }

        return n - tails.size();
    }
};