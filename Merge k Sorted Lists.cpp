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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        list<int> l1;
        for(auto head:lists){
            while(head){
                l1.push_back(head->val);
                head=head->next;
            }
        }
        l1.sort();
        // cout<<"l1.size == "<<l1.size()<<"\n";
        if(l1.size()==0){ 
             // ListNode *head=new ListNode(0);
            // return head;
            return NULL;
        }
        ListNode *head=new ListNode(*l1.begin());
        ListNode *temp=head;
        for(auto it=next(l1.begin());it!=l1.end();++it) 
        {    temp->next = new ListNode(*it);
                temp=temp->next;
        }
        temp->next=NULL;
        return head;
        
    }
};
