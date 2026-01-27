abstract class Animal {
    abstract void sound();

    public void eat() {
        System.out.println("This animal is eating");
    }
}

class Dog extends Animal {
    @Override
    void sound() {
        System.out.println("Dog barks");
    }
}

public class Main {
    static final String species = "Mammal";

    public static void main(String[] args) {
        System.out.println("Species: " + species);

        Animal a = new Dog();
        a.sound();   
        a.eat();    
    }
}
