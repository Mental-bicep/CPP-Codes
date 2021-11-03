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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return head;
        if(head->next==NULL and n==1) return NULL;
    ListNode *prev=head,*ptr=head;;
    for(int i=1;i<=n;++i) head=head->next;
    
    ListNode*temp=prev;
    while(head){
        
        head=head->next;
        temp=prev;
        prev=prev->next;
    }
    if(temp==prev){
        auto ptr1=temp->next;
        temp->next=NULL;
        return ptr1;
    }
    temp->next=temp->next->next;
    return ptr;
    }
};
