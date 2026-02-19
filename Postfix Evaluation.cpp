#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int evaluatePostfix(vector<string> &arr)
    {
        stack<int> s;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == "+")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b + a);
            }
            else if (arr[i] == "-")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b - a);
            }
            else if (arr[i] == "*")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b * a);
            }
            else if (arr[i] == "/")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                int q = b / a, r = b % a;
                if (r != 0 && ((r > 0) != (a > 0)))
                {
                    q--;
                }
                s.push(q);
            }
            else if (arr[i] == "^")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(pow(b, a));
            }
            else
            {
                s.push(stoi(arr[i]));
            }
        }

        return s.top();
    }
};