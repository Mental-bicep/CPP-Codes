/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode * fun(ListNode *head)
    {
        if(!head->next) return head;
        auto ele=fun(head->next);
        head->next->next=head;
        head->next=NULL;
        return ele;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        return fun(head);
    }
};
