#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countIncreasing(vector<int> &arr)
    {
        int cnt = 1, ans = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i - 1] < arr[i])
            {
                cnt++;
            }
            else
            {
                if (cnt >= 2)
                {
                    ans += (cnt * (cnt - 1)) / 2;
                }

                cnt = 1;
            }
        }

        if (cnt >= 2)
        {
            ans += (cnt * (cnt - 1)) / 2;
        }

        return ans;
    }
};