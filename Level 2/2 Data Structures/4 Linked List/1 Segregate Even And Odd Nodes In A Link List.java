import java.util.*;

class Main {
    public static class ListNode {
        int val = 0;
        ListNode next = null;

        ListNode(int val) {
            this.val = val;
        }
    }

    public static ListNode segregateEvenOdd(ListNode head) {
        ListNode even = new ListNode(0), odd = new ListNode(0);
        ListNode enode = even;
        ListNode onode = odd;
        
        ListNode node = head;
        while(node != null){
            if(node.val % 2 == 0){
                enode.next = new ListNode(node.val);
                enode = enode.next;
            } else{
                onode.next = new ListNode(node.val);
                onode = onode.next;
            }
            node = node.next;
        }
        
        enode.next = odd.next;
        return even.next;
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        ListNode dummy = new ListNode(-1);
        ListNode prev = dummy;
        while (n-- > 0) {
            prev.next = new ListNode(scn.nextInt());
            prev = prev.next;
        }

        ListNode head = segregateEvenOdd(dummy.next);
        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
    }
}