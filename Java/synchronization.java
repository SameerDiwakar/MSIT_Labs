 
class Shared {
     
    synchronized void syncMethod() {
        System.out.println(Thread.currentThread().getName() + ": Inside synchronized method");
        try {
            Thread.sleep(1000);  
        } catch (InterruptedException e) {
            System.out.println("Thread interrupted");
        }
    }
 
    void syncBlock() {
        synchronized (this) {
            System.out.println(Thread.currentThread().getName() + ": Inside synchronized block");
            try {
                Thread.sleep(1000); 
            } catch (InterruptedException e) {
                System.out.println("Thread interrupted");
            }
        }
    }
}
 
class MyThread extends Thread {
    Shared obj;

    MyThread(Shared obj) {
        this.obj = obj;
    }

    @Override
    public void run() {
        obj.syncMethod();
        obj.syncBlock();
    }
}
 
public class Main {
    public static void main(String[] args) {
        Shared obj = new Shared();

        MyThread t1 = new MyThread(obj);
        MyThread t2 = new MyThread(obj);

        t1.setName("Thread-1");
        t2.setName("Thread-2");

        t1.start();
        t2.start();
    }
}
