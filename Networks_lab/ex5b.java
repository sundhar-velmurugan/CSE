import java.net.Socket;
import java.io.BufferedReader;
import java.io.PrintStream;
import java.io.InputStreamReader;
import java.util.Scanner;

public class ex5b{
    public static void main(String []args) throws Exception{
        Socket soc = new Socket("localhost", 2000);
        BufferedReader br = new BufferedReader(new InputStreamReader(soc.getInputStream()));
        PrintStream ps = new PrintStream(soc.getOutputStream());
        System.out.println("Pinging Server:");
        int i=1;
        while(i<5){
            Thread.sleep(1000);
            long t1 = System.currentTimeMillis();
            ps.println(i);
            String got = br.readLine();
            long t2 = System.currentTimeMillis()-t1;
            String time = Long.toString(t2);
            System.out.println("Reply from Server: " +got+" Time: "+time);
            i++;
        }
        ps.close();
        br.close();
        soc.close();
    }
}