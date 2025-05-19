public class Throw {
    public static void validate(int age) throws ArithmeticException {
        if (age < 18) {
            throw new ArithmeticException("Not Eligible");
        }
        System.out.println("Eligible");
    }

    public static void main(String[] args) {
        try {
            validate(16);  
        } catch (ArithmeticException e) {
            System.out.println("Exception caught: " + e.getMessage());
        }
    }
}
