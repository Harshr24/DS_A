import java.util.Scanner;

class Node {
    int data;
    Node next;
}

class LinkedList {
    Node head;

    Node createNode(int data) {
        Node newNode = new Node();
        newNode.data = data;
        newNode.next = null;
        return newNode;
    }

    void insertFromHead(int data) {
        Node newNode = createNode(data);
        newNode.next = head;
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
        if (current == null) {
            System.out.println("Position out of range!");
            return;
        }
        newNode.next = current.next;
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

public class Single_Linked_List_Insertion {
    public static void main(String[] args) {
        LinkedList linkedList = new LinkedList();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of elements in the linked list: ");
        int n = sc.nextInt();
        System.out.println("Enter elements to insert into the linked list:");
        for (int i = 0; i < n; i++) {
            int data = sc.nextInt();
            linkedList.insertFromTail(data);
        }
        linkedList.displayList();
        while (true) {
            System.out.println("\n1. Insert from head\n2. Insert from tail\n3. Insert at position\n4. Exit");
            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();
            switch (choice) {
                case 1:
                    System.out.print("Enter data to insert at the head: ");
                    int data = sc.nextInt();
                    linkedList.insertFromHead(data);
                    linkedList.displayList();
                    break;
                case 2:
                    System.out.print("Enter data to insert at the tail: ");
                    data = sc.nextInt();
                    linkedList.insertFromTail(data);
                    linkedList.displayList();
                    break;
                case 3:
                    System.out.print("Enter data to insert at a position: ");
                    data = sc.nextInt();
                    System.out.print("Enter position: ");
                    int position = sc.nextInt();
                    linkedList.insertAtPosition(data, position);
                    linkedList.displayList();
                    break;
                case 4:
                    System.exit(0);
                default:
                    System.out.println("Invalid choice!");
                    break;
            } sc.close();
        }
    }
}
