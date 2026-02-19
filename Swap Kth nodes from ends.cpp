#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *swapKth(Node *head, int k)
    {
        int n = 0;
        Node *ptr = head;
        while (ptr)
        {
            ptr = ptr->next;
            n++;
        }

        if (k > n)
        {
            return head;
        }

        Node *first = head;
        for (int i = 1; i < k; i++)
        {
            first = first->next;
        }

        Node *last = head;
        for (int i = 1; i <= n - k; i++)
        {
            last = last->next;
        }

        swap(first->data, last->data);
        return head;
    }
};