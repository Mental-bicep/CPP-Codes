#define rn return 
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
    ListNode * left;
    bool fun(ListNode *head)
    {   
        if(!head) rn true;
        if(fun(head->next)==false) rn false;
        if(left==head)
        {
            head->next=NULL;
            return false;   
        }
        if(left->next==head)
        {
            head->next=NULL;
            return false;
        }
        auto temp=left->next;
        left->next=head;
        head->next=temp;
        left=temp;
        rn true;
        
        
    }
    void reorderList(ListNode* head) {
        left=head;
        fun(head);
    }
};
