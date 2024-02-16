import java.util.Scanner;
import java.util.Stack;

public class StackExample {
    private static final int MAX = 10;
    private Stack<Integer> stack = new Stack<>();
    
    public void push(int value) {
        if (stack.size() == MAX) {
            System.out.println("Error: Stack overflow!");
        } else {
            stack.push(value);
        }
    }
    
    public Integer pop() {
        if (stack.isEmpty()) {
            System.out.println("Error: Stack underflow!");
            return null;
        } else {
            return stack.pop();
        }
    }
    
    public void peep() {
        if (stack.isEmpty()) {
            System.out.println("Error: Stack is empty!");
        } else {
            for (int i = 0; i < stack.size(); i++) {
                System.out.print(stack.get(i) + " | ");
            }
            System.out.println();
        }
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        StackExample stackExample = new StackExample();
        int choice, value;
        
        while (true) {
            System.out.println("1. Push\n2. Pop\n3. Peep\n4. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();
            
            switch (choice) {
                case 1:
                    System.out.print("Enter value to push: ");
                    value = scanner.nextInt();
                    stackExample.push(value);
                    break;
                case 2:
                    Integer poppedValue = stackExample.pop();
                    if (poppedValue != null) {
                        System.out.println("Popped value: " + poppedValue);
                    }
                    break;
                case 3:
                    stackExample.peep();
                    break;
                case 4:
                    System.out.println("Thank You... Exitingggggggg !!!");
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid choice!");
            }
        }
    }
}
