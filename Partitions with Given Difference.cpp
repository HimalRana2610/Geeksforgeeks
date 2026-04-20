#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPartitions(vector<int> &arr, int diff)
    {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
        }

        if (sum - diff < 0 || (sum - diff) % 2 != 0)
        {
            return 0;
        }

        int target = (sum - diff) / 2;
        vector<int> prev(target + 1, 0), curr(target + 1, 0);

        if (arr[0] == 0)
        {
            prev[0] = 2;
        }
        else
        {
            prev[0] = 1;
            if (arr[0] <= target)
            {
                prev[arr[0]] = 1;
            }
        }

        for (int i = 1; i < arr.size(); i++)
        {
            for (int j = 0; j <= target; j++)
            {
                int notTake = prev[j], take = 0;
                if (arr[i] <= j)
                {
                    take = prev[j - arr[i]];
                }
                curr[j] = (take + notTake) % 1000000007;
            }

            prev = curr;
        }

        return prev[target];
    }
};