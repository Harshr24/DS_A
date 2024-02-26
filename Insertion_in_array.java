import java.util.*;

public class insert_arr {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter array size: ");
    int s = sc.nextInt();
    int[] a = new int[s];
    System.out.println("Enter array elements: ");
    for (int i = 0; i < s; i++) {
      a[i] = sc.nextInt();
    }
    System.out.println("Enter value to be inserted: ");
    int val = sc.nextInt();
    System.out.println("Enter index where value should be inserted: ");
    int index = sc.nextInt();
    
    if (index < 0 || index > s) {    
      System.out.println("Invalid index. Index should be between 0 and " + (s - 1));
      return;
    }
    
    // Shift elements to the right of the insertion index one position to the right
    for (int i = s - 1; i >= index; i--) {
      a[i + 1] = a[i];
    }
    
    // Insert the new value at the insertion index
    a[index] = val;
    
    System.out.println("New array after insertion: ");
    for (int num : a) {
      System.out.print(num + " ");
    }
  }
}
