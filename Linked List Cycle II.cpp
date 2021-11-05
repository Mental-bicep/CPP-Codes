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
    ListNode *detectCycle(ListNode *head) {
    if(head==NULL ) return head;
    ListNode *fast=head,*slow=head;
        bool flag=false;
    while(fast->next and fast->next->next){
        
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow) {
            flag=true;
            break;
        }
    }
    if(!flag) return NULL;
        fast=head;      
        while(fast!=slow){   // learn the floyds proof for this
            fast=fast->next;
            slow=slow->next;
        }
        return fast;
    }
};
