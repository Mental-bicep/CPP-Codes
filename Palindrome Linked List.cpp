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
    
    ListNode * mid(ListNode *head)
    {
        ListNode *fast,*slow;
        fast=slow=head;
        while(fast->next and fast->next->next) {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    
    ListNode * reverse(ListNode *head)
    {
        ListNode *prev=NULL;
        while(head)
        {
            ListNode *next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next) return true;
        ListNode *node=mid(head);
        ListNode* temp=node->next;
        node->next=NULL;
        temp=reverse(temp);
        while(temp)
        {
            if(temp->val!=head->val) return false;
            temp=temp->next;
            head=head->next;
        }
        return true;
    }
};
