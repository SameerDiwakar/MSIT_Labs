class MyClass {
    String name;

    MyClass(String name) {
        this.name = name;
    }

    MyClass updateName(MyClass obj) {
        obj.name = "Update" + obj.name;
        return obj;
    }
}

public class Main {
    public static void main(String[] args) {
        MyClass obj1 = new MyClass("Original");
        MyClass obj2 = new MyClass("Test");

        System.out.println(obj1.name);
        obj1 = obj1.updateName(obj2);
        System.out.println(obj1.name);
    }
}
