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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode *dummy =new ListNode(-200);
        ListNode *prev=dummy;
        while(head)
        {   
            // cout<<"prev->val and head->val"<<prev->val<<" "<<head->val<<"\n";
            if(prev->val==-200 or prev->val!=head->val)
            {
                // cout<<"adding "<<head->val<<"\n";
                prev->next=head;
                prev=prev->next;
                
            }
            head=head->next;
            prev->next=NULL;
        }
        // ListNode *temp=dummy;
        // while(temp 
        return dummy->next;
    }
};
