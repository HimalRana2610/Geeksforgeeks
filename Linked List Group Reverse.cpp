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
    Node *reverseKGroup(Node *head, int k)
    {
        Node *temp = head;
        int node = 0;

        while (temp != NULL && node < k)
        {
            temp = temp->next;
            node++;
        }

        Node *curr = head;
        Node *prev = NULL;
        Node *next = NULL;
        int cnt = 0;

        while (curr != NULL && cnt < node)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }

        if (next != NULL)
        {
            head->next = reverseKGroup(next, k);
        }

        return prev;
    }
};