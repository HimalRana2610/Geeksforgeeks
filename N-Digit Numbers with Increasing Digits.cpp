#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int rem, int digit, int current, vector<int> &ans)
    {
        if (rem == 0)
        {
            ans.push_back(current);
            return;
        }

        for (int next = digit + 1; next <= 9; next++)
        {
            solve(rem - 1, next, current * 10 + next, ans);
        }
    }

    vector<int> increasingNumbers(int n)
    {
        vector<int> ans;
        if (n == 1)
        {
            for (int digit = 0; digit <= 9; digit++)
            {
                ans.push_back(digit);
            }

            return ans;
        }

        if (n > 9)
        {
            return ans;
        }

        for (int first = 1; first <= 9; first++)
        {
            solve(n - 1, first, first, ans);
        }

        return ans;
    }
};