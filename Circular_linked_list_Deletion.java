import java.util.Scanner;

class Node {
    int data;
    Node next;
    Node(int data) {
        this.data = data;
        this.next = this; // Point to itself to form a circular structure
    }
}

class CircularLinkedList {
    Node head = null;

    void insert(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
        } else {
            Node last = head;
            while (last.next != head) {
                last = last.next;
            }
            newNode.next = head;
            last.next = newNode;
        }
    }

    void deleteFromStart() {
        if (head == null) {
            System.out.println("List is empty!");
        } else if (head.next == head) {
            head = null;
        } else {
            Node last = head;
            while (last.next != head) {
                last = last.next;
            }
            head = head.next;
            last.next = head;
        }
    }

    void deleteFromEnd() {
        if (head == null) {
            System.out.println("List is empty!");
        } else if (head.next == head) {
            head = null;
        } else {
            Node last = head;
            Node prev = null;
            while (last.next != head) {
                prev = last;
                last = last.next;
            }
            prev.next = head;
        }
    }

    void deleteFromPosition(int position) {
        if (head == null) {
            System.out.println("List is empty!");
        } else {
            Node curr = head;
            Node prev = null;
            for (int i = 1; i < position; i++) {
                prev = curr;
                curr = curr.next;
            }
            prev.next = curr.next;
        }
    }

    void display() {
        if (head != null) {
            Node temp = head;
            do {
                System.out.print(temp.data + " ");
                temp = temp.next;
            } while (temp != head);
            System.out.println();
        }
    }
}

public class Circular_linked_list_Deletion {
    public static void main(String[] args) {
        CircularLinkedList list = new CircularLinkedList();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();
        System.out.println("Enter elements:");
        for (int i = 0; i < n; i++) {
            list.insert(sc.nextInt());
        }
        list.display();
        while (true) {
            System.out.println("\n1. Delete from head\n2. Delete from tail\n3. Delete at position\n4. Exit");
            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();
            switch (choice) {
                case 1:
                    list.deleteFromStart();
                    break;
                case 2:
                    list.deleteFromEnd();
                    break;
                case 3:
                    System.out.print("Enter position to delete: ");
                    int position = sc.nextInt();
                    list.deleteFromPosition(position);
                    break;
                case 4:
                    System.exit(0);
                default:
                    System.out.println("Invalid choice!");
            }
            System.out.println("Updated list:");
            list.display();
        }
    }
}
