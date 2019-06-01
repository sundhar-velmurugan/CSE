import java.util.Scanner;

public class Input{
    public static void main(String[] args) throws Exception{
        Scanner s = new Scanner(System.in);
        System.out.print("Enter int: ");
        int a = s.nextInt();
        System.out.print("Enter float: ");
        float b = s.nextFloat();
        System.out.print("Enter char: ");
        char c = s.next().charAt(0);
        System.out.print("Enter long: ");
        long d = s.nextLong();
        System.out.print("Enter double: ");
        double e = s.nextDouble();
        System.out.print("Enter string1: ");
        String f = s.next();
        System.out.print("Enter string2: ");
        String g = s.nextLine();
        System.out.println("int: "+a);
        System.out.println("float: "+b);
        System.out.println("char: "+c);
        System.out.println("long: "+d);
        System.out.println("double: "+e);
        System.out.println("string1: "+f);
        System.out.println("string2: "+g);
    }
}