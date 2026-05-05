#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isPallindrome(long long int N)
    {
        string str;
        while (N > 0)
        {
            if (N & 1)
            {
                str.push_back('1');
            }
            else
            {
                str.push_back('0');
            }
            N >>= 1;
        }

        for (int i = 0, j = str.length() - 1; i < j; i++, j--)
        {
            if (str[i] != str[j])
            {
                return 0;
            }
        }

        return 1;
    }
};