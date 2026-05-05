#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int visibleBuildings(vector<int> &arr)
    {
        int m = 0, ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (m <= arr[i])
            {
                ans++;
                m = arr[i];
            }
        }

        return ans;
    }
};