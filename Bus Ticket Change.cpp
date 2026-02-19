#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canServe(vector<int> &arr)
    {
        int five = 0, ten = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 5)
            {
                five++;
            }
            else if (arr[i] == 10)
            {
                if (five > 0)
                {
                    five--;
                    ten++;
                }
                else
                {
                    return false;
                }
            }

            else if (arr[i] == 20)
            {
                if (ten > 0 && five > 0)
                {
                    ten--;
                    five--;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }
                else
                {
                    return false;
                }
            }
        }

        return true;
    }
};