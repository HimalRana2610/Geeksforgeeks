#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decodedString(string &s)
    {
        stack<int> cnt;
        stack<string> str;
        string ans = "";
        int k = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i]))
            {
                k = k * 10 + (s[i] - '0');
            }
            else if (s[i] == '[')
            {
                cnt.push(k);
                str.push(ans);
                k = 0;
                ans = "";
            }
            else if (s[i] == ']')
            {
                string temp = ans;
                ans = str.top();
                str.pop();
                int t = cnt.top();
                cnt.pop();
                while (t--)
                {
                    ans += temp;
                }
            }
            else
            {
                ans += s[i];
            }
        }

        return ans;
    }
};