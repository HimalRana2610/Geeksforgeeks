#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permuteDist(vector<int> &arr)
    {
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        do
        {
            res.push_back(arr);
        } while (next_permutation(arr.begin(), arr.end()));
        return res;
    }
};