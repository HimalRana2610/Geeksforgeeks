#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &arr, int k)
    {
        int n = arr.size(), product = 1;

        sort(arr.begin(), arr.end());
        if (arr[n - 1] == 0 && (k & 1))
        {
            return 0;
        }

        if (arr[n - 1] <= 0 && (k & 1))
        {
            for (int i = n - 1; i >= n - k; i--)
            {
                product *= arr[i];
            }

            return product;
        }

        int left = 0, right = n - 1;
        if (k & 1)
        {
            product *= arr[right];
            right--;
            k--;
        }

        k /= 2;
        for (int i = 0; i < k; i++)
        {
            int leftProduct = arr[left] * arr[left + 1], rightProduct = arr[right] * arr[right - 1];
            if (leftProduct > rightProduct)
            {
                product *= leftProduct;
                left += 2;
            }
            else
            {
                product *= rightProduct;
                right -= 2;
            }
        }

        return product;
    }
};