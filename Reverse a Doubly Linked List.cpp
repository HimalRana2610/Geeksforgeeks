#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *temp = NULL;
        Node *current = head;

        while (current != NULL)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != NULL)
        {
            head = temp->prev;
        }

        return head;
    }
};