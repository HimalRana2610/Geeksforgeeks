#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> &arr)
    {
        int m = 0, ans = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            int cnt = count(arr[i].begin(), arr[i].end(), 1);
            if (cnt > m)
            {
                m = cnt;
                ans = i;
            }
        }

        return ans;
    }
};