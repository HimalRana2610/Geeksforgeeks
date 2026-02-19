#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(string &digits, string current, int target, int index, int eval, int last, vector<string> &ans)
    {
        if (index == digits.length())
        {
            if (eval == target)
            {
                ans.push_back(current);
            }
            return;
        }

        for (int i = index; i < digits.length(); i++)
        {
            if (i != index && digits[index] == '0')
            {
                break;
            }

            string next = digits.substr(index, i - index + 1);
            int num = stoll(next);

            if (index == 0)
            {
                solve(digits, next, target, i + 1, num, num, ans);
            }
            else
            {
                solve(digits, current + "+" + next, target, i + 1, eval + num, num, ans);
                solve(digits, current + "-" + next, target, i + 1, eval - num, -num, ans);
                solve(digits, current + "*" + next, target, i + 1, eval - last + last * num, last * num, ans);
            }
        }
    }

    vector<string> findExpr(string &s, int target)
    {
        vector<string> ans;
        solve(s, "", target, 0, 0, 0, ans);

        return ans;
    }
};