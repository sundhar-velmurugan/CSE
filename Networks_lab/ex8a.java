import java.net.ServerSocket;
import java.net.Socket;
import java.io.PrintStream;
import java.io.BufferedReader;
import java.io.FileReader;

public class ex8a{
    public static void main (String []args) throws Exception{
        ServerSocket server = new ServerSocket(2000);
        Socket soc = server.accept();
        PrintStream ps = new PrintStream(soc.getOutputStream());
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        String temp = br.readLine();
        while(temp!=null){
            ps.println(temp);
            temp = br.readLine();
        }
        br.close();
        ps.close();
        soc.close();
        server.close();
    }
}