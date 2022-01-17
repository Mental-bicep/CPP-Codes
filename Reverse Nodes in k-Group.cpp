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
    int length (ListNode *head)
    {
        int cnt=0;
        while(head){
            ++cnt;
            head=head->next;
        }
        return  cnt;
    }
    
    pair<ListNode *,ListNode *> fun(ListNode *head, int k,int cnt)   //head,tail
    {
        if(head==NULL) return pair<ListNode*,ListNode*> {NULL,NULL};
        if(cnt<k)
        {
            ListNode * temp=head;
            while(temp->next) temp=temp->next;
            return pair<ListNode*,ListNode*> {head,temp};
        }
        ListNode *temp=head;
        for(int i=0;i<k-1;++i) temp=temp->next;
        ListNode * t1=temp->next;
        temp->next=NULL;
        pair<ListNode*,ListNode*> p1 =fun(t1,k,cnt-k);
        ListNode *prev=NULL,*curr=head;
        ListNode *tail=head;
        while(curr)
        {
            ListNode * t=curr->next;
            curr->next=prev;
            prev=curr;
            curr=t;
        }
        tail->next=p1.first;
        return pair<ListNode*,ListNode*> {prev,p1.second};
        
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head or !head->next or k==0) return  head;
        int cnt=length(head);
        auto ele=fun(head,k,cnt);
        return ele.first;
    }
    
    
};
