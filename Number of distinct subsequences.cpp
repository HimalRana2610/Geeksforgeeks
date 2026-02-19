#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int distinctSubseq(string &str)
    {
        vector<int> last(26, 0);
        int ans = 1;

        for (int i = 1; i <= str.length(); i++)
        {
            long long temp = 2 * ans - last[str[i - 1] - 'a'];
            if (temp < 0)
            {
                temp += 1000000007;
            }

            int current = temp % 1000000007;
            last[str[i - 1] - 'a'] = ans;
            ans = current;
        }

        return ans;
    }
};