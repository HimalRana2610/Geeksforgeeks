#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

class Solution
{
public:
    unordered_map<Node *, int> dp;
    int getMaxSum(Node *root)
    {
        if (!root)
            return 0;
        if (dp.count(root))
            return dp[root];

        int include = root->data;
        if (root->left)
            include += getMaxSum(root->left->left) + getMaxSum(root->left->right);
        if (root->right)
            include += getMaxSum(root->right->left) + getMaxSum(root->right->right);

        int exclude = getMaxSum(root->left) + getMaxSum(root->right);

        dp[root] = max(include, exclude);
        return dp[root];
    }
};