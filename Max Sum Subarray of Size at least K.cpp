#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSumWithK(vector<int> &arr, int k)
    {
        int sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += arr[i];
        }

        int last = 0, j = 0, ans = sum;
        for (int i = k; i < arr.size(); i++)
        {
            sum = sum + arr[i];
            last = last + arr[j++];
            ans = max(ans, sum);

            if (last < 0)
            {
                sum = sum - last;
                ans = max(ans, sum);
                last = 0;
            }
        }

        return ans;
    }
};