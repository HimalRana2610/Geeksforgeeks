#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void replaceElements(vector<int> &arr)
    {
        int n = arr.size(), prev = arr[0];
        arr[0] ^= arr[1];

        for (int i = 1; i < n - 1; i++)
        {
            int temp = prev ^ arr[i + 1];
            prev = arr[i];
            arr[i] = temp;
        }
        arr[n - 1] ^= prev;
    }
};