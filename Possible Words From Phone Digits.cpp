#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<int> &arr, int index, string current, vector<string> &mapping, vector<string> &ans)
    {
        if (index == arr.size())
        {
            ans.push_back(current);
            return;
        }

        if (arr[index] == 0 || arr[index] == 1)
        {
            solve(arr, index + 1, current, mapping, ans);
            return;
        }

        for (int i = 0; i < mapping[arr[index]].size(); i++)
        {
            current.push_back(mapping[arr[index]][i]);
            solve(arr, index + 1, current, mapping, ans);
            current.pop_back();
        }
    }

    vector<string> possibleWords(vector<int> &arr)
    {
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;

        solve(arr, 0, "", mapping, ans);
        return ans;
    }
};