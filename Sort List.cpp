/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1==null ) return l2;
        if(l2==null) return l1;
        ListNode prev=null;
        ListNode oh=null; 
        while(l1!=null && l2!=null)
        {
            if(l1.val<=l2.val)
            {
                if(oh==null)
                {
                    oh=l1;
                    prev=oh;
                }
                else{
                prev.next=l1;
                prev=prev.next;
                }
                l1=l1.next;
            }
            else{
                if(oh==null)
                {
                    oh=l2;
                    prev=oh;
                }else{
                prev.next=l2;
                prev=prev.next;
                }
                l2=l2.next;
            }
            
        }
        if(l1!=null) prev.next=l1;
        if(l2!=null) prev.next=l2;
        return oh;
    }
    
    public ListNode mid(ListNode head)
    {
        ListNode slow,fast;
        slow=fast=head;
        while(fast.next!=null && fast.next.next!=null){
            fast=fast.next.next;
            slow=slow.next;
        }
        return slow;
    }
    
    public ListNode fun(ListNode head)
    {
        if(head.next==null) return head;
        ListNode middle=mid(head);
        ListNode temp=middle.next;
        middle.next=null;
        ListNode l1=fun(head);
        ListNode l2=fun(temp);
        return mergeTwoLists(l1,l2); 
    }
    
    
    public ListNode sortList(ListNode head) {
        if(head==null) return head;
        return fun(head);
    }
}
