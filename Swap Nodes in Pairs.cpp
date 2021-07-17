/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL ||head->next==NULL)
            return head;
        ListNode *ptr=head,*temp,*prev;
        temp=ptr->next;
        ptr->next=temp->next;
        temp->next=ptr;
        head=temp;
        prev=ptr;
        ptr=ptr->next;
        while(ptr && ptr->next)
        {   temp=ptr->next;
            ptr->next=ptr->next->next;
         temp->next=ptr;
         prev->next=temp;
         prev=ptr;
         ptr=ptr->next;
        }
            return head;
    }
};
