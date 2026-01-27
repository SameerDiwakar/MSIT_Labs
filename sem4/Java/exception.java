public class ExceptionDemo {
    public static void main(String[] args) {
        try {
            int res = 10 / 0;
            System.out.println("Result: " + res);
        } catch (ArithmeticException e) {
            System.out.println("Exception caught: " + e.getMessage());
        } finally {
            System.out.println("Finally block executed");
        }
    }
}

