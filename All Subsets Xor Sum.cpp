#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subsetXORSum(vector<int> &arr)
    {
        int n = arr.size(), all = 0;
        for (int i = 0; i < n; i++)
        {
            all |= arr[i];
        }

        return all * (1 << (n - 1));
    }
};