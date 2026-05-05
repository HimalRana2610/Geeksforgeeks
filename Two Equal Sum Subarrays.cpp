#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canSplit(vector<int> &arr)
    {
        int n = arr.size();
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (prefix[i + 1] == prefix[n] - prefix[i + 1])
            {
                return true;
            }
        }

        return false;
    }
};