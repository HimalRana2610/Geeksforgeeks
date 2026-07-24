#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find(vector<int> &arr)
    {
        int ans = 0;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            ans = (ans + arr[i] + 1) / 2;
        }

        return ans;
    }
};