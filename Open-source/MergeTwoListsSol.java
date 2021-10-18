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
        
        ListNode temp_head= new ListNode(0);
        ListNode l3=temp_head;
        
        while(l1!=null && l2!=null){
            
            if(l1.val<l2.val){
                ListNode newNode= new ListNode(l1.val);
                l3.next= newNode;
                l3= l3.next;
                l1=l1.next;
            }
            
            else{
                ListNode newNode= new ListNode(l2.val);
                l3.next= newNode;
                l3= l3.next;
                l2=l2.next; 
            }
        }
        
        while(l1!=null){
                ListNode newNode= new ListNode(l1.val);
                l3.next= newNode;
                l3= l3.next;
                l1=l1.next; 
        }
        
        while(l2!=null){
                ListNode newNode= new ListNode(l2.val);
                l3.next= newNode;
                l3= l3.next;
                l2=l2.next; 
        }
        
        return temp_head.next;
        
    }
}