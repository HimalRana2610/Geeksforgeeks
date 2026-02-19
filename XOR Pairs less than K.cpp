#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[2];
    int cnt;

    TrieNode()
    {
        children[0] = children[1] = nullptr;
        cnt = 0;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(int num, int maxBit)
    {
        TrieNode *node = root;
        for (int i = maxBit - 1; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->children[bit])
            {
                node->children[bit] = new TrieNode();
            }

            node = node->children[bit];
            node->cnt++;
        }
    }

    int query(int num, int k, int maxBit)
    {
        TrieNode *node = root;
        int cnt = 0;

        for (int i = maxBit - 1; i >= 0; i--)
        {
            if (!node)
            {
                break;
            }

            int numBit = (num >> i) & 1, kBit = (k >> i) & 1;
            if (kBit == 1)
            {
                if (node->children[numBit])
                {
                    cnt += node->children[numBit]->cnt;
                }
                node = node->children[1 - numBit];
            }
            else
            {
                node = node->children[numBit];
            }
        }

        return cnt;
    }
};

class Solution
{
public:
    int cntPairs(vector<int> &arr, int k)
    {
        int maxBit = 32, ans = 0;
        Trie trie;

        for (int i = 0; i < arr.size(); i++)
        {
            ans += trie.query(arr[i], k, maxBit);
            trie.insert(arr[i], maxBit);
        }

        return ans;
    }
};