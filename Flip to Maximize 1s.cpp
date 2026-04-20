#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSumSub(vector<int> &arr)
    {
        int n = arr.size(), sum = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            ans = max(ans, sum);

            if (sum < 0)
            {
                sum = 0;
            }
        }

        return ans;
    }

    int maxOnes(vector<int> &arr)
    {
        int n = arr.size(), one = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 1)
            {
                arr[i] = -1;
                one++;
            }
            else
            {
                arr[i] = 1;
            }
        }

        return one + maxSumSub(arr);
    }
};