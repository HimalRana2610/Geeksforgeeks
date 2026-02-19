#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> previousGreater(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> prev(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] < arr[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                prev[i] = st.top();
            }
            st.push(i);
        }

        return prev;
    }

    vector<int> nextGreater(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> next(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] < arr[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                next[i] = st.top();
            }
            st.push(i);
        }

        return next;
    }

    int maxPeople(vector<int> &arr)
    {
        int n = arr.size(), ans = 0;
        vector<int> prev = previousGreater(arr);
        vector<int> next = nextGreater(arr);

        for (int i = 0; i < n; i++)
        {
            int left = (prev[i] == -1 ? 0 : prev[i] + 1), right = (next[i] == n ? n - 1 : next[i] - 1);
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};