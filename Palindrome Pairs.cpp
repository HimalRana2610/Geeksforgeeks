#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool is_palindrome(string &s, int l, int r)
    {
        while (l < r)
        {
            if (s[l] != s[r])
            {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }

    bool palindromePair(vector<string> &arr)
    {
        int n = arr.size();
        unordered_map<string, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[arr[i]] = i;
        }

        for (int i = 0; i < n; i++)
        {
            string s = arr[i];
            for (int j = 0; j <= s.length(); j++)
            {
                string left = s.substr(0, j), right = s.substr(j);
                if (is_palindrome(left, 0, left.size() - 1))
                {
                    string revRight = right;
                    reverse(revRight.begin(), revRight.end());

                    if (mp.count(revRight) && mp[revRight] != i)
                    {
                        return true;
                    }
                }

                if (!right.empty() && is_palindrome(right, 0, right.size() - 1))
                {
                    string revLeft = left;
                    reverse(revLeft.begin(), revLeft.end());

                    if (mp.count(revLeft) && mp[revLeft] != i)
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};