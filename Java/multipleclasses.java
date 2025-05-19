class P {
    String n;
    int a;

    P(String n, int a) {
        this.n = n;
        this.a = a;
    }

    void show() {
        System.out.println("Name: " + n);
        System.out.println("Age: " + a);
    }
}

class A {
    String s;
    String c;

    A(String s, String c) {
        this.s = s;
        this.c = c;
    }

    void show() {
        System.out.println("Street: " + s);
        System.out.println("City: " + c);
    }
}

public class Main {
    public static void main(String[] args) {
        P p = new P("Alice", 25);
        A a = new A("123 Main St", "Springfield");

        p.show();
        a.show();
    }
}
