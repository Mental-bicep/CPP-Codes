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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
     // ListNode *head=new ListNode();
     //    ListNode *temp=head;
     //    while(l1 and l2){
     //        if(l1->val<l2->val){
     //            head->val=l1->val;
     //            head->next=new ListNode();
     //            head=head->next;
     //            l1=l1->next;
     //        }
     //        else{
     //            head->val=l2->val;
     //            head->next=new ListNode();
     //            head=head->next;
     //            l2=l2->next;
     //        }
     //    }
     //    while(l1){
     //        head->val=l1->val;
     //            head->next=new ListNode();
     //            head=head->next;
     //            l1=l1->next;
     //    }
     //    while(l2){
     //        head->val=l2->val;
     //            head->next=new ListNode();
     //            head=head->next;
     //            l2=l2->next;
     //    }
        if(l1==NULL and l2==NULL ) return NULL;
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    ListNode *prev=NULL;
    ListNode *head1=l1,*head2=l2;
    while(head1 and head2){
        if(head1->val<=head2->val) {
            prev=head1;
            
            head1=head1->next;
        }
        else{
            if(prev==NULL){
                auto temp=head2->next;
                head2->next=head1;
                prev=head2;
                l1=prev;
                head2=temp;
            }
            else{
                auto temp=head2->next;
                head2->next=head1;
                prev->next=head2;
                prev=prev->next;
                head2=temp;
            }
        }
    }
    if(head2) prev->next=head2;
    return l1;
    }
};
