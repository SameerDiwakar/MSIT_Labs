import java.util.*;
public class Ma{
  public static void Main(string[] args){
   Stack<Integer>stack = new Stack<>();
    stack.push(10);
    stack.pop();
    if (!stack.empty()){
        System.out.println("Stack after pop: "+stack.peek());
    }
    
    Queue<Integer>q = new LinkedList<>();
    q.add(200);
    System.out.println("Queue first" + q.peek());
    q.remove();
    System.out.println("Queue after deque : "+ q.peek());
  }
  
} 
