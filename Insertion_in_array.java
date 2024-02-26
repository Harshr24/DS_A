import java.util.*;

public class Insertion_in_array {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter array size: ");
    int s = sc.nextInt();
    int[] a = new int[s + 1]; // Array size should be one more than user-provided size
    System.out.println("Enter array elements: ");
    for (int i = 0; i < s; i++) {
      a[i] = sc.nextInt();
    }
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
    
    // Insert the new value at the insertion index
    a[index] = val;
    
    System.out.println("New array after insertion: ");
    for (int num : a) {
      System.out.print(num + " ");
    }
    sc.close();
  }
}
