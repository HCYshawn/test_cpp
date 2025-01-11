#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeNodes(ListNode* head)
    {
        if (head->next == NULL)
            return head;
        auto node = removeNodes(head->next);
        if (node->val > head->val)
        {
            return node;
        }
        head->next = node;
        return head;
    }
};