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
      System.out.println("Array after insertion:");
      for (int num : newArray) {
        System.out.print(num + " ");
      }
*/

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


/* Way 3 : 

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

*/