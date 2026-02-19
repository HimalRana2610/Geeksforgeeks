#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthElement(vector<int> &a, vector<int> &b, int k)
    {
        int n = a.size(), m = b.size(), i = 0, j = 0;
        vector<int> merged;

        while (i < n && j < m)
        {
            if (a[i] <= b[j])
            {
                merged.push_back(a[i]);
                i++;
            }
            else
            {
                merged.push_back(b[j]);
                j++;
            }
        }

        while (i < n)
        {
            merged.push_back(a[i]);
            i++;
        }

        while (j < m)
        {
            merged.push_back(b[j]);
            j++;
        }

        return merged[k - 1];
    }
};