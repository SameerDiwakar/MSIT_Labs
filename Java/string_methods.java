public class Main {
    public static void main(String[] args) {
        String a = "Hello";
        String b = "World";
        String c = a + " " + b;

        System.out.println("Concatenated string: " +c);
        System.out.println("Length of a: " + a.length());
        System.out.println("Substring of a (1,4): " + a.substring(1, 4));
        System.out.println("a.equals(b): " + a.equals(b));
        System.out.println("a.equalsIgnoreCase(\"hello\"): " + a.equalsIgnoreCase("hello"));
        System.out.println("a to upper case: " + a.toUpperCase());
        System.out.println("b to lower case: " + b.toLowerCase());
    }
}
