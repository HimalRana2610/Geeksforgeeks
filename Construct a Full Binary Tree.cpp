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
        left = right = nullptr;
    }
};

class Solution
{
public:
    Node *construct(vector<int> &pre, vector<int> &preMirror, int &idx, int l, int r, unordered_map<int, int> &mp, int n)
    {
        if (idx >= n || l > r)
        {
            return nullptr;
        }

        Node *root = new Node(pre[idx++]);
        if (l == r)
        {
            return root;
        }

        int i = mp[pre[idx]];
        if (i >= l && i <= r)
        {
            root->left = construct(pre, preMirror, idx, i, r, mp, n);
            root->right = construct(pre, preMirror, idx, l + 1, i - 1, mp, n);
        }

        return root;
    }

    Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror)
    {
        int n = pre.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[preMirror[i]] = i;
        }

        int idx = 0;
        return construct(pre, preMirror, idx, 0, n - 1, mp, n);
    }
};