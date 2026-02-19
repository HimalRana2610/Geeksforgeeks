#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void reverseQueue(queue<int> &q)
    {
        stack<int> s;
        while (!q.empty())
        {
            s.push(q.front());
            q.pop();
        }

        while (!s.empty())
        {
            q.push(s.top());
            s.pop();
        }
    }
};