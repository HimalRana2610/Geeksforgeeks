#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool areRotations(string &s1, string &s2)
    {
        string temp = s1 + s1;
        return temp.find(s2) != string::npos;
    }
};