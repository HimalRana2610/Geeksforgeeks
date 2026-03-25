#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    void dfs(Node *node, long long sum, int k, unordered_map<long long, int> &mp, int &ans)
    {
        if (!node)
        {
            return;
        }

        sum += node->data;
        if (mp.count(sum - k))
        {
            ans += mp[sum - k];
        }

        mp[sum]++;
        dfs(node->left, sum, k, mp, ans);
        dfs(node->right, sum, k, mp, ans);
        mp[sum]--;
    }

    int countAllPaths(Node *root, int k)
    {
        unordered_map<long long, int> mp;
        mp[0] = 1;

        int ans = 0;
        dfs(root, 0, k, mp, ans);

        return ans;
    }
};