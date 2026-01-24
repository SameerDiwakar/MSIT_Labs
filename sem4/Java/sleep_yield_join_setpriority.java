class Task extends Thread {
    public void run() {
        try {
            System.out.println(Thread.currentThread().getName() + " started");
            System.out.println(Thread.currentThread().getName() + "Waking up");
            System.out.println(Thread.currentThread().getName() + " Yields");
            
            Thread.yield();

            Thread.sleep(1000);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Task t1 = new Task();
        Task t2 = new Task();
        Task t3 = new Task();

        t1.setPriority(Thread.MIN_PRIORITY);  
        t2.setPriority(Thread.NORM_PRIORITY); 
        t3.setPriority(Thread.MAX_PRIORITY);  

        t1.setName("Thread-1");
        t2.setName("Thread-2");
        t3.setName("Thread-3");

        t1.start();
        t2.start();
        t3.start();

        try {
            t1.join();
            t2.join();
            t3.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("All threads have finished");
    }
}
