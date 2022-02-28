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
    public ListNode oddEvenList(ListNode head) {
        ListNode even=null,odd=null;
        ListNode curr=head;
        ListNode oddhead=null,evenhead=null;
        int cnt=1;
        while(curr!=null)
        {
            ListNode next=curr.next;
            if(cnt%2==1) {
                if(oddhead==null) {oddhead=curr;odd=curr;}
                else {odd.next=curr;odd=odd.next;}
            }
            else {
                    if(evenhead==null) {even=curr;evenhead=even;}
                    else {even.next=curr;even=even.next;}     
            }
            ++cnt;
            curr.next=null;
            curr=next;
        }
        if(evenhead!=null && oddhead!=null)
        {
            odd.next=evenhead;
            return oddhead;
        }
        else if(evenhead!=null) return evenhead;
        else return oddhead;
    }
}
