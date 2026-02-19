#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int n, string current, vector<string> &ans)
    {
        if (current.length() == n)
        {
            ans.push_back(current);
            return;
        }

        solve(n, current + "0", ans);
        solve(n, current + "1", ans);
    }

    vector<string> binstr(int n)
    {
        vector<string> ans;
        solve(n, "", ans);

        return ans;
    }
};