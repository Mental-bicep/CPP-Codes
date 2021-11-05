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
    ListNode * reverse(ListNode *head){
    if(head==NULL or head->next==NULL) return head;
    ListNode *prev=NULL,*curr=head,*forw;
    while(curr){
        forw=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forw;
    }
    return prev;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL and l2==NULL) return NULL;
    if(l1==NULL) return l1;
    if(l2==NULL) return l2;
    ListNode *dummy=new ListNode(-1);
    ListNode *ptr=dummy;
    l2=reverse(l2);
    l1=reverse(l1);
    ListNode *curr1=l1,*curr2=l2;
    int carry=0,num=0;
    while(curr1 or curr2){
        if(curr1 and curr2)  {
            int total=curr1->val+curr2->val+carry;
            num=total%10;
            carry=total/10;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        else if(curr1){
            int total=curr1->val+carry;
            num=total%10;
            carry=total/10;
            curr1=curr1->next;
        }    
        else{
            int total=curr2->val+carry;
            num=total%10;
            carry=total/10;
            curr2=curr2->next;
        }
        ptr->next=new ListNode(num);
        ptr=ptr->next;
    }
    if(carry) {ptr->next=new ListNode(carry);ptr=ptr->next;}
        ptr->next=NULL;
    // l2=reverse(l2);
    ptr=dummy->next;
    ptr=reverse(ptr);
    return ptr;
    }
};
