#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string profession(int level, int pos)
    {
        return (__builtin_popcount(pos - 1) % 2) ? "Doctor" : "Engineer";
    }
};