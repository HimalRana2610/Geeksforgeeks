#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortIt(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> odd, even;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 0)
            {
                even.push_back(arr[i]);
            }
            else
            {
                odd.push_back(arr[i]);
            }
        }

        sort(odd.rbegin(), odd.rend());
        sort(even.begin(), even.end());

        int index = 0;
        for (int i = 0; i < odd.size(); i++)
        {
            arr[index++] = odd[i];
        }
        for (int i = 0; i < even.size(); i++)
        {
            arr[index++] = even[i];
        }
    }
};