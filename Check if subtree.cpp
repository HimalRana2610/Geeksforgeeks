#include <bits/stdc++.h>
using namespace std;

struct Node
{
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
    bool is_same(Node *root1, Node *root2)
    {
        if (!root1 && !root2)
        {
            return true;
        }

        if (!root1 || !root2)
        {
            return false;
        }

        return root1->data == root2->data && is_same(root1->left, root2->left) && is_same(root1->right, root2->right);
    }

    bool isSubTree(Node *root1, Node *root2)
    {
        if (!root1 && !root2)
        {
            return true;
        }

        if (!root1 || !root2)
        {
            return false;
        }

        if (is_same(root1, root2))
        {
            return true;
        }

        return isSubTree(root1->left, root2) || isSubTree(root1->right, root2);
    }
};