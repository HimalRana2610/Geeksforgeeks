#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int merge(vector<int> &arr, int l, int m, int r)
    {
        int n1 = m - l + 1, n2 = r - m;
        vector<int> left(n1), right(n2);

        for (int i = 0; i < n1; i++)
        {
            left[i] = arr[l + i];
        }
        for (int i = 0; i < n2; i++)
        {
            right[i] = arr[m + 1 + i];
        }

        int i = 0, j = 0, k = l, ans = 0;
        while (i < n1 && j < n2)
        {
            if (left[i] <= right[j])
            {
                arr[k++] = left[i++];
            }
            else
            {
                arr[k++] = right[j++];
                ans += (n1 - i);
            }
        }

        while (i < n1)
        {
            arr[k++] = left[i++];
        }
        while (j < n2)
        {
            arr[k++] = right[j++];
        }

        return ans;
    }

    int solve(vector<int> &arr, int l, int r)
    {
        int ans = 0;
        if (l < r)
        {
            int m = (l + r) / 2;
            ans += solve(arr, l, m) + solve(arr, m + 1, r) + merge(arr, l, m, r);
        }

        return ans;
    }

    int inversionCount(vector<int> &arr)
    {
        return solve(arr, 0, arr.size() - 1);
    }
};