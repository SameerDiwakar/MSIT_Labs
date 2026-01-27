class Calc {
    public int add(int a, int b) {
        return a + b;
    }

    public int add(int a, int b, int c) {
        return a + b + c;
    }

    public double add(double a, double b) {
        return a + b;
    }
}
 
class Animal {
    void sound() {
        System.out.println("Animal sound");
    }
}

class Dog extends Animal {
    @Override
    void sound() {
        System.out.println("Dog barks");
    }
}

class Cat extends Animal {
    @Override
    void sound() {
        System.out.println("Cat meows");
    }
}

public class Main {
    public static void main(String[] args) {
        // Compile-time polymorphism
        Calc c = new Calc();
        System.out.println("Addition of 2 ints: " + c.add(5, 3));
        System.out.println("Addition of 3 ints: " + c.add(5, 3, 2));
        System.out.println("Addition of 2 doubles: " + c.add(5.5, 3.3));

        System.out.println();  
 
        Animal a = new Animal();
        Animal d = new Dog();
        Animal ct = new Cat();

        a.sound();    
        d.sound();    
        ct.sound();  
    }
}
