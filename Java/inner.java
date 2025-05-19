public class Main {
  
    interface MyInterface {
        void show();   
    }
    class MemberInner {
        void display() {
            System.out.println("Member Inner Class");
        }
    }

    public static void main(String[] args) {
         
        Main outer = new Main(); 
        MemberInner m = outer.new MemberInner(); 
        m.display();
 
  
        MyInterface obj = new MyInterface() {
            @Override
            public void show() {
                System.out.println("Anonymous Inner Class implementing MyInterface");
            }
        };
        obj.show();
  
        class LocalInner {
            void display() {
                System.out.println("Local Inner Class");
            }
        }
         
        LocalInner l = new LocalInner();
        l.display();
  
        StaticInner s = new StaticInner();
        s.display();
        
        MyInterface obj2 = new MyInterface() {
            @Override
            public void show() {
                System.out.println("Nested Interface implementation");
            }
        };
        obj2.show();
    }
 
    static class StaticInner {
        void display() {
            System.out.println("Static Inner Class");
        }
    }
}
