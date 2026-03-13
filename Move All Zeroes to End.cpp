#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void pushZerosToEnd(vector<int> &arr)
    {
        int n = arr.size(), pos = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 0)
            {
                arr[pos++] = arr[i];
            }
        }

        while (pos < n)
        {
            arr[pos++] = 0;
        }
    }
};