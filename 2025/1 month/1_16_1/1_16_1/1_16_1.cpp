#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//LC206 反转链表（新解法）

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* p1 = nullptr;
        ListNode* p2 = head;
        while (p2)
        {
            ListNode* p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }
        return p1;
    }
};