
/**
@Author Douly
Given an array of binary number, you need to store it in a linked list, with each element of array being a node of link list.
Now this linkedlist represents a binary number. You need to return the number in base 10.
**/

public class LinkedListToInteger {

	public static void main(String[] args) {
		int[] input = new int[]{1,0,1};
		Node linkedList = linkedListFromArray(input);
		int value = binaryLinkedListToDecimal(linkedList);
		
		System.out.println(value);
		
	}
	
	/**
	 Converts array of integer to a Linked List and returns the head/initial node of linked list
	**/
	private static Node linkedListFromArray(int[] arr) {
		int decimalValue = 0;
		Node head = new Node(arr[0]);
		Node temp = head;
		for(int i=1;i<arr.length;i++) {
		   Node currentNode = new Node(arr[i]);
		   temp.setNext(currentNode);
		   temp=currentNode;
		}
		return head;
	}

	/**
	 Takes the binary linked list as input and convert it to decimal equivalent.It iterates over the list and calculate the length.In 		 second iteration, for each element it sums the product of node value and its position's power of 2
	**/
	private static int binaryLinkedListToDecimal(Node head) {
		int decimalValue=0;
		Node temp = head;

		int lengthOfList = 0;
		while(temp!=null) {
			lengthOfList++;
			temp=temp.getNext();
		}
    
		temp = head;
		while(temp!=null) {
			decimalValue = decimalValue + (int)(temp.getData()*Math.pow(2,--lengthOfList));
			temp=temp.getNext();
		}
		
		return decimalValue;	
	}


	public static class Node {
		
		private int data;
                private Node next;
                
                public Node(int value) {
			this.data = value;
			this.next = null;
		}
		
		public int getData(){
			return this.data;
		}

		public Node getNext(){
			return this.next;
		}

		public void setNext(Node node){
			this.next = node;
		}
		
	}
}
