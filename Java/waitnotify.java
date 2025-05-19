import java.util.Scanner;

class SharedData {
    private boolean ready = false;
    private String message;

    public synchronized void waitForData() throws InterruptedException {
        while (!ready) {
            System.out.println("Waiting for data");
            wait();
        }
        System.out.println("Received message: " + message);
    }

    public synchronized void modifyAndNotify(String msg) {
        this.message = msg;
        this.ready = true;
        System.out.println("Data modified and notifying all waiting threads...");
        notifyAll();
    }
    public synchronized void modifyAndNotifyOne(String msg) {
        this.message = msg;
        this.ready = true;
        System.out.println("Data modified. Notifying ONE waiting thread...");
        notify(); 
    }
}

public class Main {
    public static void main(String[] args) {
        SharedData sharedData = new SharedData();

        Thread waitingThread = new Thread(() -> {
            try {
                sharedData.waitForData();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                System.out.println("Waiting thread interrupted");
            }
        });

        waitingThread.start();

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter message to send: ");
        String message = scanner.nextLine();
        scanner.close();

        sharedData.modifyAndNotify(message);
    }
}
