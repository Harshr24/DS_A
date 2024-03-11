import java.util.Scanner;

class Node {
    int data;
    Node next;
}

class LinkedList {
    Node head;

    void insert(int value) {
        Node newNode = new Node();
        newNode.data = value;
        newNode.next = null;
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

    void display() {
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

    void deleteFirstNode() {
        Node toDelete;
        if (head == null) {
            System.out.println("List is already empty.");
            return;
        }
        toDelete = head;
        head = head.next;
        System.out.println("\nData deleted = " + toDelete.data);
        System.out.println("SUCCESSFULLY DELETED FIRST NODE FROM LIST");
    }
