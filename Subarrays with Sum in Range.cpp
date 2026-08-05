#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &arr, int x)
    {
        int sum = 0, ans = 0;
        for (int i = 0, j = 0; j < arr.size(); j++)
        {
            sum += arr[j];
            while (i <= j && sum > x)
            {
                sum -= arr[i++];
            }
            ans += j - i + 1;
        }

        return ans;
    }

    int countSubarray(vector<int> &arr, int l, int r)
    {
        return solve(arr, r) - solve(arr, l - 1);
    }
};