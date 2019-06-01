import java.net.InetAddress;
import java.util.Scanner;

public class ex1{
    public static void main (String []args) throws Exception{
        InetAddress address = InetAddress.getLocalHost();
        System.out.println("Host Name: "+address.getHostName());
        System.out.println("Host Address: "+address.getHostAddress());
        System.out.print("Enter the Address: ");
        Scanner s = new Scanner(System.in);
        String addr = s.nextLine();
        address = InetAddress.getByName(addr);
        System.out.println("Host Name: "+address.getHostName());
        System.out.println("Host Address: "+address.getHostAddress());
    }
}