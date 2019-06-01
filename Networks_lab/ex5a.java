import java.net.ServerSocket;
import java.net.Socket;
import java.io.BufferedReader;
import java.io.PrintStream;
import java.io.InputStreamReader;

public class ex5a{
    public static void main(String []args) throws Exception{
        ServerSocket server = new ServerSocket(2000);
        Socket soc = server.accept();
        BufferedReader br = new BufferedReader(new InputStreamReader(soc.getInputStream()));
        PrintStream ps = new PrintStream(soc.getOutputStream());
        System.out.println("Server Ready");
        int i=0;
        while(i!=4){
            String temp = br.readLine();
            i = Integer.parseInt(temp);
            System.out.println("From Client: "+i);
            ps.println(i);
        }        
        ps.close();
        br.close();
        soc.close();
        server.close();
    }
}