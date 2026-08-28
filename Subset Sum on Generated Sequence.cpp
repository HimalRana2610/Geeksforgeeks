#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &arr, int s, int x)
    {
        long long sum = s;
        vector<long long> paper = {s};

        for (int i = 0; i < arr.size(); i++)
        {
            long long current = sum + arr[i];
            paper.push_back(current);
            sum += current;
        }

        long long target = x;
        for (int i = paper.size() - 1; i >= 0; i--)
        {
            if (paper[i] <= target)
            {
                target -= paper[i];
            }
        }

        return target == 0;
    }
};