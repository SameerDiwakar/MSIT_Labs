class A {
    int x;

    A(int x) {
        this.x = x; 
    }

    void show() {
        System.out.println("A: " + x);
    }
}

class B extends A {
    int y;

    B(int x, int y) {
        super(x);
        this.y = y;   
    }

    void show() {
        super.show(); 
        System.out.println("B: " + y);
    }
}

public class Main {
    public static void main(String[] args) {
        B b = new B(5, 10);
        b.show();
    }
}
