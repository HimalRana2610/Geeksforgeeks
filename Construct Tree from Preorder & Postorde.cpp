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
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node *solve(vector<int> &pre, vector<int> &post, int &index, int l, int r, int n, unordered_map<int, int> &mp)
    {
        if (index >= n || l > r)
        {
            return nullptr;
        }

        Node *root = new Node(pre[index++]);
        if (l == r)
        {
            return root;
        }

        int pos = mp[pre[index]];
        if (pos <= r)
        {
            root->left = solve(pre, post, index, l, pos, n, mp);
            root->right = solve(pre, post, index, pos + 1, r - 1, n, mp);
        }

        return root;
    }
    Node *constructTree(vector<int> &pre, vector<int> &post)
    {
        int index = 0, n = pre.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[post[i]] = i;
        }

        return solve(pre, post, index, 0, n - 1, n, mp);
    }
};