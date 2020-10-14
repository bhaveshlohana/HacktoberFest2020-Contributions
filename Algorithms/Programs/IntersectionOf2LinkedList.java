/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        HashMap<ListNode,Integer> mapA = new HashMap<>();
        ListNode temp1 = headA;
        while(temp1 != null)
        {
            mapA.put(temp1,temp1.val);
            temp1 = temp1.next;
        }
        ListNode temp2 = headB;
        while(temp2 != null)
        {
           if(mapA.containsKey(temp2))
           {
               return temp2;
           }
            temp2 = temp2.next;
        }
        return null;
    }
}
