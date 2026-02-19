#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarrayRanges(vector<int> &arr)
    {
        int n = arr.size();
        long long ma = 0, mi = 0;

        stack<int> max_st;
        for (int i = 0; i <= n; i++)
        {
            while (!max_st.empty() && (i == n || arr[max_st.top()] < arr[i]))
            {
                int idx = max_st.top();
                max_st.pop();

                int left = max_st.empty() ? -1 : max_st.top(), right = i;
                ma += (long long)(idx - left) * (right - idx) * arr[idx];
            }
            max_st.push(i);
        }

        stack<int> min_st;
        for (int i = 0; i <= n; i++)
        {
            while (!min_st.empty() && (i == n || arr[min_st.top()] > arr[i]))
            {
                int idx = min_st.top();
                min_st.pop();
                int left = min_st.empty() ? -1 : min_st.top(), right = i;
                mi += (long long)(idx - left) * (right - idx) * arr[idx];
            }
            min_st.push(i);
        }

        return ma - mi;
    }
};