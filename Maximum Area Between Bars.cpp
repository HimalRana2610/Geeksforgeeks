#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int i = 0, j = height.size() - 1, ans = 0;
        while (i < j)
        {
            int width = j - i - 1;
            if (height[i] < height[j])
            {
                ans = max(ans, width * height[i++]);
            }
            else if (height[j] < height[i])
            {
                ans = max(ans, width * height[j--]);
            }
            else
            {
                ans = max(ans, width * height[i++]);
                j--;
            }
        }

        return ans;
    }
};