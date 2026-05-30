#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void find_valid(string str, int index, int open, int close, int pair, string current, vector<string> &ans, unordered_set<string> &st)
    {
        if (index == str.size())
        {
            if (open == 0 && close == 0 && pair == 0)
            {
                if (st.find(current) == st.end())
                {
                    ans.push_back(current);
                    st.insert(current);
                }
            }
            return;
        }

        if (str[index] != '(' && str[index] != ')')
        {
            find_valid(str, index + 1, open, close, pair, current + str[index], ans, st);
        }
        else
        {
            if (str[index] == '(')
            {
                if (open > 0)
                {
                    find_valid(str, index + 1, open - 1, close, pair, current, ans, st);
                }

                find_valid(str, index + 1, open, close, pair + 1, current + str[index], ans, st);
            }

            else
            {
                if (close > 0)
                {
                    find_valid(str, index + 1, open, close - 1, pair, current, ans, st);
                }
                if (pair > 0)
                {
                    find_valid(str, index + 1, open, close, pair - 1, current + str[index], ans, st);
                }
            }
        }
    }

    vector<string> validParenthesis(string &s)
    {
        vector<string> ans;
        unordered_set<string> st;

        int open = 0, close = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                open++;
            }

            if (s[i] == ')')
            {
                if (open != 0)
                {
                    open--;
                }

                else
                {
                    close++;
                }
            }
        }

        find_valid(s, 0, open, close, 0, "", ans, st);
        sort(ans.begin(), ans.end());

        return ans;
    }
};