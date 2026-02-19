#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countLessEqual(vector<int> &arr, int x)
    {
        sort(arr.begin(), arr.end());

        return upper_bound(arr.begin(), arr.end(), x) - arr.begin();
    }
};