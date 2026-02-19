#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string firstNonRepeating(string &s)
    {
        unordered_map<char, int> freq;
        queue<char> q;
        string ans = "";

        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            freq[ch]++;
            q.push(ch);

            while (!q.empty())
            {
                if (freq[q.front()] > 1)
                {
                    q.pop();
                }
                else
                {
                    ans.push_back(q.front());
                    break;
                }
            }

            if (q.empty())
            {
                ans.push_back('#');
            }
        }

        return ans;
    }
};