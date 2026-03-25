#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class BST
{
public:
    int mn, mx, size;

    BST(int mn, int mx, int size)
    {
        this->mn = mn;
        this->mx = mx;
        this->size = size;
    }
};

class Solution
{
public:
    BST solve(Node *node)
    {
        if (!node)
        {
            return BST(INT_MAX, INT_MIN, 0);
        }

        BST left = solve(node->left), right = solve(node->right);
        if (left.mx < node->data && right.mn > node->data)
        {
            return BST(min(left.mn, node->data), max(right.mx, node->data), 1 + left.size + right.size);
        }

        return BST(INT_MIN, INT_MAX, max(left.size, right.size));
    }

    int largestBst(Node *root)
    {
        return solve(root).size;
    }
};