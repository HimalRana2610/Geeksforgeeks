#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> graycode(int n)
    {
        vector<string> ans;
        int size = pow(2, n);

        for (int i = 0; i < size; i++)
        {
            int num = i ^ (i >> 1);
            string s = "";

            for (int j = n - 1; j >= 0; j--)
            {
                s += to_string((num >> j) & 1);
            }

            ans.push_back(s);
        }

        return ans;
    }
};