#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
//LC 1290 二进制链表转整数

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    int getDecimalValue(ListNode* head)
    {
        int ret = 0;
        ListNode* left = head;
        while (left != NULL)
        {
            int i = 0;
            ListNode* mid = left;
            while (mid->next != NULL)
            {
                i++;
                mid = mid->next;
            }
            ret += (left->val) * pow(2, i);
            left = left->next;
        }
        return ret;
    }
};