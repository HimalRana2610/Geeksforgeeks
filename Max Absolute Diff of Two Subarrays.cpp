#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> build_left(vector<int> &arr)
    {
        int n = arr.size(), m = arr[0], current = arr[0];
        vector<int> ans(n);
        ans[0] = m;

        for (int i = 1; i < n; i++)
        {
            current = max(arr[i], current + arr[i]);
            m = max(m, current);
            ans[i] = m;
        }

        return ans;
    }

    vector<int> build_right(vector<int> &arr)
    {
        int n = arr.size(), m = arr[n - 1], current = arr[n - 1];
        vector<int> ans(n);
        ans[n - 1] = m;

        for (int i = n - 2; i >= 0; i--)
        {
            current = max(arr[i], current + arr[i]);
            m = max(m, current);
            ans[i] = m;
        }

        return ans;
    }

    int maxDiffSubArrays(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> inverted = arr;

        for (int i = 0; i < n; i++)
        {
            inverted[i] = -inverted[i];
        }

        vector<int> lmn = build_left(inverted), rmn = build_right(inverted);
        for (int i = 0; i < n; i++)
        {
            lmn[i] = -lmn[i];
        }
        for (int i = 0; i < n; i++)
        {
            rmn[i] = -rmn[i];
        }

        int ans = INT_MIN;
        vector<int> lmx = build_left(arr), rmx = build_right(arr);

        for (int i = 0; i < n - 1; i++)
        {
            ans = max(ans, max(abs(lmx[i] - rmn[i + 1]), abs(lmn[i] - rmx[i + 1])));
        }

        return ans;
    }
};