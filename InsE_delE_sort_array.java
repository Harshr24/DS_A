import java.util.*;


public class InsE_delE_sort_array {
  
  public static void sortArray(int[] arr) {
    int n = arr.length;
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
          int temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
      }
    }
  }

  public static void insertElement(int[] a, int s) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter value to be inserted: ");
    int val = sc.nextInt();
    System.out.println("Enter index where value should be inserted: ");
    int index = sc.nextInt();
    
    if (index < 0 || index > s) {    
      System.out.println("Invalid index. Index should be between 0 and " + s);
    }
    // Shift elements to the right of the insertion index one position to the right
    for (int i = s - 1; i >= index; i--) {
      a[i + 1] = a[i]; // Shift elements to the right starting from the last element
    }
    a[index] = val;    // Insert the new value at the insertion index

      /* Way 2 : Create a new array and then insert it  
        int[] newArray = new int[size + 1];   // Create a new array with increased size
        for (int i = 0, j = 0; i < newArray.length; i++)      // Copy elements from the original array to the new array
        {
          if (i == index) {
            newArray[i] = value; // Insert the new value at the specified index
          } else {
            newArray[i] = array[j++]; // Copy elements from the original array
          }
        }
    */
    System.out.println("New array after insertion: ");
    for (int num : a) {
      System.out.print(num + " ");
    }
    sc.close();
  }

  public static void deleteElement(int[] a, int s) {
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter the index of the element to delete (0 to " + (s - 1) + "): ");
    int del_idx = sc.nextInt();
    if (del_idx < 0 || del_idx >= s) {
      System.out.println("Invalid index! Please enter an index between 0 and " + (s - 1));
    }
    for (int i = del_idx; i < s - 1; i++) {
        a[i] = a[i + 1];          // Shift elements to the left to overwrite the element 
    }
    s--;		  // Decrease the size of the array
    
    /* Way 2 : Create a new array and then Delete within it  
        int[] newArray = new int[size - 1]; // Create a new array with size reduced by one
        // Copy elements from the original array to the new array excluding the element to delete
        for (int i = 0, j = 0; i < size; i++) {
          if (i != indexToDelete) {
            newArray[j++] = array[i];
          }
        }
    */

    System.out.println("Array after deleting the element:");
    for (int i = 0; i < s; i++) {
      System.out.print(a[i] + " ");
    }
    sc.close();
  }

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter array size: ");
    int s = sc.nextInt();
    int[] a = new int[s + 1]; // Array size should be one more than user-provided size
    System.out.println("Enter array elements: ");
    for (int i = 0; i < s; i++) {
      a[i] = sc.nextInt();
    }
    int choice;

    do {
      System.out.println("1. Insert element");
      System.out.println("2. Delete element");
      System.out.println("3. Sort array");
      System.out.println("4. Exit");
      System.out.print("Enter your choice: ");
      choice = sc.nextInt();
      switch (choice) {
        case 1:
          insertElement(a, s);
          break;
        case 2:
          deleteElement(a, s);
          break;
        case 3:
          sortArray(a);
          System.out.println("Sorted array:");
          for (int num : a) {
            System.out.print(num + " ");
          }
          break;
        case 4:
          System.out.println("Exiting...");
          break;
        default:
          System.out.println("Invalid choice! Please enter a valid choice.");
      }
      sc.close();
    } while (choice != 4);
  }
}


/* Way 3 : Using array list : 
Insertion : 
  import java.util.*;
  public class Insert1 {
    public static void main(String[] args) {
        Integer aray[] = {25, 30, 35, 40, 45};
        int sz = aray.length;
        System.out.print("The given array: ");
        for(int i = 0; i < sz; i++) {
          System.out.print(aray[i] + " ");
        }
        System.out.println();
        ArrayList<Integer> arayList = new           // creating an ArrayList with old array
        ArrayList<Integer>(Arrays.asList(aray));
        arayList.add(50); 				// adding new element
        System.out.print("The new array after appending the element: " + arayList);
    }
  }

Deletion : 
  import java.util.*;
  public class RemoveElement {
  public static void main(String[] args) {
          Scanner scanner = new Scanner(System.in);
          ArrayList<Integer> list = new ArrayList<>();
          System.out.print("Enter the number of elements: ");
          int n = scanner.nextInt();
          System.out.println("Enter the elements:");
          for (int i = 0; i < n; i++) {
              list.add(scanner.nextInt());
          }
          System.out.print("Enter the index to remove: ");
          int index = scanner.nextInt();
          if (index >= 0 && index < list.size()) {
          list.remove(index);
          System.out.println("Element at index " + index + " removed successfully.");
          } else {
              System.out.println("Invalid index!");
          }
          System.out.println("List after removal: " + list);
      }
  }

*/