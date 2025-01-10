#define _CRT_SECURE_NO_WARNINGS 1
//LC2181 合并零之间的结点

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeNodes(ListNode* head)
    {
        auto tail = head;
        for (auto mid = head->next; mid->next; mid = mid->next)
        {
            if (mid->val)
            {
                tail->val += mid->val;
            }
            else
            {
                tail = tail->next;
                tail->val = 0;
            }

        }
        tail->next = nullptr;
        return head;
    }
};