#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string &s)
    {
        if (s.size() > 3 || s.empty() || (s[0] == '0' && s.size() > 1) || stoi(s) > 255)
        {
            return false;
        }

        return true;
    }

    vector<string> generateIp(string &s)
    {
        vector<string> ans;
        int n = s.size();

        for (int i = 1; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    string a = s.substr(0, i);
                    string b = s.substr(i, j - i);
                    string c = s.substr(j, k - j);
                    string d = s.substr(k);

                    if (isValid(a) && isValid(b) && isValid(c) && isValid(d))
                    {
                        ans.push_back(a + "." + b + "." + c + "." + d);
                    }
                }
            }
        }

        return ans;
    }
};