project_folder/
│
├── mypackage/
│   └── Myclass.java
│
└── Main.java
package mypackage;

public class Myclass {
    public void display() {
        System.out.println("Hello from Myclass in mypackage!");
    }
}
import mypackage.Myclass;

public class Main {
    public static void main(String[] args) {
        Myclass Myobj = new Myclass();
        Myobj.display();
    }
}
