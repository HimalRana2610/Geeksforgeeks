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
    Node *find_lca(Node *root, int p, int q)
    {
        if (!root)
        {
            return nullptr;
        }

        if (root->data == p || root->data == q)
        {
            return root;
        }

        Node *left = find_lca(root->left, p, q);
        Node *right = find_lca(root->right, p, q);

        if (left && right)
        {
            return root;
        }

        return left ? left : right;
    }

    bool find_path(Node *root, int target, string &path)
    {
        if (!root)
        {
            return false;
        }

        if (root->data == target)
        {
            return true;
        }

        path.push_back('L');
        if (find_path(root->left, target, path))
        {
            return true;
        }
        path.pop_back();

        path.push_back('R');
        if (find_path(root->right, target, path))
        {
            return true;
        }
        path.pop_back();

        return false;
    }

    int cnt_turns(string &path)
    {
        int ans = 0;
        for (int i = 1; i < path.length(); i++)
        {
            if (path[i] != path[i - 1])
            {
                ans++;
            }
        }

        return ans;
    }

    int numberOfTurns(Node *root, int p, int q)
    {
        Node *lca = find_lca(root, p, q);
        if (!lca)
        {
            return -1;
        }

        string first = "", second = "";
        find_path(lca, p, first);
        find_path(lca, q, second);

        int ans = 0;
        if (lca->data == p || lca->data == q)
        {
            ans = cnt_turns((lca->data == p) ? second : first);
        }
        else
        {
            ans = cnt_turns(first) + cnt_turns(second) + 1;
        }

        return ans == 0 ? -1 : ans;
    }
};