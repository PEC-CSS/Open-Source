package Problems;
import java.util.Scanner;

public class Nth_Nodes_from_End_of_Linked_Lists {
    public static void main(String[] args){
        System.out.print("Enter the length of the Linked List :");
        Scanner s = new Scanner(System.in);
        int L=s.nextInt();
        System.out.println("Enter the elements of the Linked Lists");
        System.out.println("Enter -1 to stop");
        Node head = null, tail = null;
        int data = s.nextInt();
        while (data != -1) {
            Node newNode = new Node(data);
            if (head == null) {
                head = newNode;
                tail = newNode;

            } else {
                tail.next = newNode;
                tail = tail.next;

            }
            data = s.nextInt();
        }
        System.out.println("Enter N ");
        int N=s.nextInt();
        System.out.println(getNthFromLast(head,N));
    }
    public static int getNthFromLast(Node head, int n){
        int size=1,i=0;
        Node cur=head;
        while(cur!=null)
        {
            size++;
            cur=cur.next;
        }

        size=(size-n)-1;
        cur=head;
        while(cur!=null)
        {
            if(i==size)
                return cur.data;
            i++;
            cur=cur.next;
        }
        return -1;

    }

}

class Node{
    int data;
    Node next;
    Node(int data){
        this.data=data;
        next=null;
    }
}