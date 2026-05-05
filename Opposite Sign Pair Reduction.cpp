#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> reducePairs(vector<int> &arr)
    {
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++)
        {
            while (!ans.empty() && ans.back() * arr[i] < 0)
            {
                if (abs(ans.back()) > abs(arr[i]))
                {
                    arr[i] = ans.back();
                    ans.pop_back();
                }
                else if (abs(ans.back()) < abs(arr[i]))
                {
                    ans.pop_back();
                }
                else
                {
                    ans.pop_back();
                    arr[i] = 0;
                    break;
                }
            }

            if (arr[i] != 0)
            {
                ans.push_back(arr[i]);
            }
        }

        return ans;
    }
};