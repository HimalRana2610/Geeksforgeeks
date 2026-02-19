#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCandy(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ratings(n, 1);

        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[i - 1])
            {
                ratings[i] = ratings[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] > arr[i + 1])
            {
                ratings[i] = max(ratings[i], ratings[i + 1] + 1);
            }
        }

        return accumulate(ratings.begin(), ratings.end(), 0);
    }
};