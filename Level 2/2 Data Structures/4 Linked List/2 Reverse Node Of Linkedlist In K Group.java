// not solved completely
import java.util.*;

class Main {
    public static Scanner scn = new Scanner(System.in);

    public static class ListNode {
        int val = 0;
        ListNode next = null;

        ListNode(int val) {
            this.val = val;
        }
    }

    private static ListNode oh = null, ot = null;
    private static ListNode th = null, tt = null;
    private static void addFirstNode(ListNode node){
        if(th == null){
            th = tt = node;
        } else{
            node.next = th;
            th = node;
        }
    }
    
    private static int length(ListNode node){
        ListNode temp = node;
        int len = 0;
        while(temp != null){
            temp = temp.next;
            len++;
        }
        return len;
    }
    
    public static ListNode reverseInKGroup(ListNode head, int k) {
        if(head == null || head.next == null || k <= 1){
            return head;
        }
        
        int len = length(head);
        ListNode curr = head;
        while(len > 1){
            if(len >= k){
                int tempk = k;
                while(tempk-- > 0){
                    ListNode next = curr.next;
                    curr.next = null;
                    addFirstNode(curr);
                    curr = next;
                }
            } else{
                ListNode next = curr.next;
                curr.next = null;
                curr = next;
                th = tt = curr;
            }
            
            if(oh == null){
                oh = th;
            } else{
                ot.next = th;
            }
            ot = tt;
            th = tt = null;
        }
        
        return oh;
    }

    public static void printList(ListNode node) {
        while (node != null) {
            System.out.print(node.val + " ");
            node = node.next;
        }
    }

    public static ListNode createList(int n) {
        ListNode dummy = new ListNode(-1);
        ListNode prev = dummy;
        while (n-- > 0) {
            prev.next = new ListNode(scn.nextInt());
            prev = prev.next;
        }

        return dummy.next;
    }

    public static void main(String[] args) {
        int n = scn.nextInt();
        ListNode h1 = createList(n);

        int k = scn.nextInt();
        h1 = reverseInKGroup(h1, k);
        printList(h1);
    }
}