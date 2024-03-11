import java.util.*;

class Node {
    int data;
    Node next;

    public Node(int data) {     // Constructor to initialize the node
        this.data = data;
        this.next = null;
    }
}


class LinkedList {
    Node head;

    public LinkedList() {
        head = null;
    }

    public void insert(int value) {
        Node newNode = new Node(value);

        if (head == null) {                 // If the linked list is empty, set the head as the new node
            head = newNode;
        } else {                            // Else, traverse to the last node and insert the new node there
            Node current = head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = newNode;
        }
    }

    public void display() {
        if (head == null) {
            System.out.println("Linked list is empty.");
            return;
        }

        Node current = head;
        System.out.print("Linked list: ");
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

    public void deleteFirstNode() {
        if (head == null) {
            System.out.println("List is already empty.");
            return;
        }

        Node toDelete = head;               // Store the node to be deleted
        head = head.next;                   // Set the head as the next node of the current head

        System.out.println("\nData deleted = " + toDelete.data);
        System.out.println("SUCCESSFULLY DELETED FIRST NODE FROM LIST");
    }
}

public class Single_Linked_List_Deletion {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LinkedList linkedList = new LinkedList();

        System.out.print("Enter number of elements in the linked list: ");
        int n = sc.nextInt();

        System.out.println("Enter elements to insert into the linked list:");
        for (int i = 0; i < n; i++) {
            int value = sc.nextInt();
            linkedList.insert(value);
        }

        linkedList.display();
        linkedList.deleteFirstNode();
        linkedList.display();

        sc.close();
    }
}
