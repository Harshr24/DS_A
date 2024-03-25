import java.util.Scanner;

class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = this; // In a circular linked list, initially, the node points to itself.
    }
}

class CircularLinkedList {
    Node head;

    void insertFromHead(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
        } else {
            Node tail = head;
            while (tail.next != head) {
                tail = tail.next;
            }
            newNode.next = head;
            tail.next = newNode;
        }
        head = newNode;
    }

    void insertFromTail(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
        } else {
            Node tail = head;
            while (tail.next != head) {
                tail = tail.next;
            }
            tail.next = newNode;
            newNode.next = head;
        }
    }

    void insertAtPosition(int data, int position) {
        if (position < 0) {
            System.out.println("Invalid position!");
            return;
        }
        Node newNode = new Node(data);
        if (position == 0 || head == null) {
            insertFromHead(data);
            return;
        }
        Node current = head;
        Node prev = null;
        int index = 0;
        do {
            prev = current;
            current = current.next;
            if (++index == position) break;
        } while (current != head);

        if (index < position) {
            System.out.println("Position out of range!");
            return;
        }
        prev.next = newNode;
        newNode.next = current;
    }

    void displayList() {
        if (head != null) {
            Node current = head;
            do {
                System.out.print(current.data + " ");
                current = current.next;
            } while (current != head);
            System.out.println();
        }
    }
}

public class Circular_linked_list_Insertion {
    public static void main(String[] args) {
        CircularLinkedList circularLinkedList = new CircularLinkedList();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of elements in the linked list: ");
        int n = sc.nextInt();
        System.out.println("Enter elements to insert into the linked list:");
        for (int i = 0; i < n; i++) {
            int data = sc.nextInt();
            circularLinkedList.insertFromTail(data);
        }
        circularLinkedList.displayList();
        while (true) {
            System.out.println("\n1. Insert from head\n2. Insert from tail\n3. Insert at position\n4. Exit");
            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();
            switch (choice) {
                case 1:
                    System.out.print("Enter data to insert at the head: ");
                    int data = sc.nextInt();
                    circularLinkedList.insertFromHead(data);
                    circularLinkedList.displayList();
                    break;
                case 2:
                    System.out.print("Enter data to insert at the tail: ");
                    data = sc.nextInt();
                    circularLinkedList.insertFromTail(data);
                    circularLinkedList.displayList();
                    break;
                case 3:
                    System.out.print("Enter data to insert at a position: ");
                    data = sc.nextInt();
                    System.out.print("Enter position: ");
                    int position = sc.nextInt();
                    circularLinkedList.insertAtPosition(data, position);
                    circularLinkedList.displayList();
                    break;
                case 4:
                    sc.close();
                    System.exit(0);
                default:
                    System.out.println("Invalid choice!");
                    break;
            }
        }
    }
}
