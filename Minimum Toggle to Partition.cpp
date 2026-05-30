#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minToggle(vector<int> &arr)
    {
        int one = 0, ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 1)
            {
                one++;
            }
            else
            {
                ans = min(ans + 1, one);
            }
        }

        return ans;
    }
};