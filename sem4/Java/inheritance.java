
class Main{
    public static void main(String[] args){
        Animal a = new Animal();
        Dog d = new Dog();
        Puppy p = new Puppy();
        a.sound();
        d.sound();
        p.sound();
    }
}
class Animal{

  void sound(){
      System.out.println("Dog barks");
  }
}
class Dog extends Animal{
    void sound(){
        System.out.println("Dog barks");
    }
}
class Puppy extends Dog{
    void sound(){
        System.out.println("Puppy yaps");
    }
    
}
