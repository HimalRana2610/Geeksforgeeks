#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findUnion(vector<int> &a, vector<int> &b)
    {
        unordered_set<int> s(a.begin(), a.end());
        for (int i = 0; i < b.size(); i++)
        {
            s.insert(b[i]);
        }

        return vector<int>(s.begin(), s.end());
    }
};