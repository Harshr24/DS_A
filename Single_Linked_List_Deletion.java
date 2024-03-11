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

    public void deleteLastNode() {
        if (head == null) {
            System.out.println("List is already empty.");
            return;
        }
        Node toDelete = head;                       // Initialize two pointers: toDelete and secondLastNode
        Node secondLastNode = null;

        while (toDelete.next != null) {             // Iterate through the list until we reach the last node
            secondLastNode = toDelete;              // Update secondLastNode to point to the current node

            toDelete = toDelete.next;               // Move toDelete to the next node in the list
        }

        if (toDelete == head) {
            head = null;                            // if the last node is the head node, set head node to null
        } else {
            secondLastNode.next = null;
        }
        System.out.println("Last node deleted successfully.");
    }
    
    void deleteMiddleNode(int position) {
            int i;
            if (head == null) {
                System.out.println("List is already empty.");
                return;
            }
            Node toDelete = head;
            Node prevNode = head;
            for (i = 2; i <= position; i++) {
                prevNode = toDelete;                // move the previous pointer one step behind
                toDelete = toDelete.next;           // move the toDelete pointer one step ahead
                if (toDelete == null) break;
            }
            if (toDelete != null) {
                if (toDelete == head) head = head.next;     // if the node to delete is the head node
                prevNode.next = toDelete.next;              // update the next pointer of the previous node to skip the node to delete
                toDelete.next = null;                       // set the next pointer of the node to delete to null
                System.out.println("SUCCESSFULLY DELETED NODE FROM MIDDLE OF LIST");
            } else {
                System.out.println("Invalid position unable to delete.");
            }
    }
}

public class Single_Linked_List_Deletion {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        LinkedList linkedList = new LinkedList();
        System.out.print("Enter number of elements in the linked list: ");
        int n = scanner.nextInt();
        System.out.println("Enter elements to insert into the linked list:");
        for (int i = 0; i < n; i++) {
            int value = scanner.nextInt();
            linkedList.insert(value);
        }
        linkedList.display();
        System.out.print("Enter 1 to delete the first node, 2 to delete the middle node, 3 to delete the last node: ");
        int choice = scanner.nextInt();
        switch (choice) {
            case 1:
                linkedList.deleteFirstNode();
                break;
            case 2:
                System.out.print("Enter position of the node to delete: ");
                int position = scanner.nextInt();
                linkedList.deleteMiddleNode(position);
                break;
            case 3:
                linkedList.deleteLastNode();
                break;
            default:
                System.out.println("Invalid choice.");
                break;
        }
        linkedList.display();
    }
}
