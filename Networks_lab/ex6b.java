import java.net.Socket;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Scanner;

public class ex6b{
    public static void main(String []args) throws Exception{
        Socket soc = new Socket("localhost", 2000);
        BufferedReader br = new BufferedReader(new InputStreamReader(soc.getInputStream()));
        PrintStream ps = new PrintStream(soc.getOutputStream());
        Scanner s = new Scanner(System.in);
        
        System.out.println("Client Ready.");
        String input="";
        while(!input.equals("bye")){
            System.out.print("Client : ");
            input = s.nextLine();
            ps.println(input);
            String msg = br.readLine();
            System.out.println("Server : "+msg);
        }
        ps.close();
        br.close();
        soc.close();
    }
}