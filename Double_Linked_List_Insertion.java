import java.util.Scanner;

class Node {
    int data;
    Node next;
    Node prev;
}

class DoublyLinkedList {
    Node head;

    Node createNode(int data) {
        Node newNode = new Node();
        newNode.data = data;
        newNode.next = null;
        newNode.prev = null;
        return newNode;
    }

    void insertFromHead(int data) {
        Node newNode = createNode(data);
        newNode.next = head;
        if (head != null) {
            head.prev = newNode;
        }
        head = newNode;
    }

    void insertFromTail(int data) {
        Node newNode = createNode(data);
        if (head == null) {
            head = newNode;
        } else {
            Node current = head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = newNode;
            newNode.prev = current;
        }
    }

    void insertAtPosition(int data, int position) {
        if (position < 0) {
            System.out.println("Invalid position!");
            return;
        }
        if (position == 0) {
            insertFromHead(data);
            return;
        }
        Node newNode = createNode(data);
        Node current = head;
        for (int i = 1; i < position && current != null; i++) {
            current = current.next;
        }
        if (current == null || current.next == null) {
            System.out.println("Position out of range!");
            return;
        }
        newNode.next = current.next;
        newNode.prev = current;
        current.next.prev = newNode;
        current.next = newNode;
    }

    void displayList() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }
}

public class Double_Linked_List_Insertion {
    public static void main(String[] args) {
        DoublyLinkedList doublyLinkedList = new DoublyLinkedList();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of elements in the linked list: ");
        int n = sc.nextInt();
        System.out.println("Enter elements to insert into the linked list:");
        for (int i = 0; i < n; i++) {
            int data = sc.nextInt();
            doublyLinkedList.insertFromTail(data);
        }
        doublyLinkedList.displayList();
        while (true) {
            System.out.println("\n1. Insert from head\n2. Insert from tail\n3. Insert at position\n4. Exit");
            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();
            switch (choice) {
                case 1:
                    System.out.print("Enter data to insert at the head: ");
                    int data = sc.nextInt();
                    doublyLinkedList.insertFromHead(data);
                    doublyLinkedList.displayList();
                    break;
                case 2:
                    System.out.print("Enter data to insert at the tail: ");
                    data = sc.nextInt();
                    doublyLinkedList.insertFromTail(data);
                    doublyLinkedList.displayList();
                    break;
                case 3:
                    System.out.print("Enter data to insert at a position: ");
                    data = sc.nextInt();
                    System.out.print("Enter position: ");
                    int position = sc.nextInt();
                    doublyLinkedList.insertAtPosition(data, position);
                    doublyLinkedList.displayList();
                    break;
                case 4:
                    System.exit(0);
                default:
                    System.out.println("Invalid choice!");
                    break;
            }
        }
    }
}
