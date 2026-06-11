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
        next = nullptr;
    }
};

class Solution
{
public:
    Node *reverseList(Node *head)
    {
        Node *curr = head;
        Node *prev = nullptr;
        Node *next;

        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    Node *compute(Node *head)
    {
        head = reverseList(head);
        Node *curr = head;
        Node *maxnode = head;
        Node *temp;

        while (curr != nullptr && curr->next != nullptr)
        {
            if (curr->next->data < maxnode->data)
            {
                temp = curr->next;
                curr->next = temp->next;
                delete (temp);
            }
            else
            {
                curr = curr->next;
                maxnode = curr;
            }
        }

        return reverseList(head);
    }
};