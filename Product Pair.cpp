#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isProduct(vector<int> &arr, long long target)
    {
        unordered_set<long long> s;
        for (int i = 0; i < arr.size(); i++)
        {
            if (target == 0 && arr[i] == 0)
            {
                return true;
            }

            if (target % arr[i] == 0)
            {
                if (s.find(target / arr[i]) != s.end())
                {
                    return true;
                }
                s.insert(arr[i]);
            }
        }

        return false;
    }
};