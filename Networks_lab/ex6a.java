import java.net.ServerSocket;
import java.net.Socket;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Scanner;

public class ex6a{
    public static void main(String []args) throws Exception{
        ServerSocket server = new ServerSocket(2000);
        Socket soc = server.accept();
        BufferedReader br = new BufferedReader(new InputStreamReader(soc.getInputStream()));
        PrintStream ps = new PrintStream(soc.getOutputStream());
        Scanner s = new Scanner(System.in);
        
        System.out.println("Server Ready.");
        String input="";
        while(!input.equals("bye")){
            input = br.readLine();
            System.out.println("Client Message: "+input);
            System.out.print("Server Message: ");
            String msg = s.nextLine();
            ps.println(msg);
        }
        ps.close();
        br.close();
        soc.close();
        server.close();
    }
}