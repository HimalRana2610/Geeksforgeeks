#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void segregate0and1(vector<int> &arr)
    {
        int low = 0, high = arr.size() - 1;
        while (low < high)
        {
            while (arr[low] == 0 && low < high)
            {
                low++;
            }

            while (arr[high] == 1 && low < high)
            {
                high--;
            }

            if (low < high)
            {
                swap(arr[low], arr[high]);
                low++;
                high--;
            }
        }
    }
};