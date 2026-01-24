class MyThread extends Thread {
    public void run() {
        System.out.println("Thread is running");
    }
}

public class Main {
    public static void main(String[] args) {
        Thread t1 = new MyThread();
        t1.start();
    }
}

class MyTask extends Thread { 
    String taskName;

    MyTask(String name) {
        this.taskName = name;
    }

    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println(taskName + " - Count: " + i);
            try {
                Thread.sleep(500);  
            } catch (InterruptedException e) {
                System.out.println(taskName + " interrupted");
            }
        }
    }
}

public class Main {
    public static void main(String[] args) {
        MyTask t1 = new MyTask("Thread A");
        MyTask t2 = new MyTask("Thread B");

        t1.start();
        t2.start();
    }
}
