import java.lang.Process;
import java.lang.Runtime;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class ex2{
    public static void main (String []args) throws Exception{
        /*String cmd = "tracert www.google.com";
        Process p = Runtime.getRuntime().exec(cmd);
        BufferedReader br = new BufferedReader(new InputStreamReader(p.getInputStream()));
        br.readLine();
        br.readLine();
        br.readLine();
        br.readLine();
        br.readLine();
        String s = br.readLine();
        String h = s.split("\\s+")[5];
        System.out.println(h);
        
        while(read!=null){
            System.out.println(read);
            read=br.readLine();
        }
        ----------------------------------------------------------
        String cmd = "arp -a";
        Process p = Runtime.getRuntime().exec(cmd);
        BufferedReader br = new BufferedReader(new InputStreamReader(p.getInputStream()));
        String s = br.readLine();
        while(s!=null){
            System.out.println(s);
            s=br.readLine();
        }
        */
        String cmd = "nslookup localhost";
        Process p = Runtime.getRuntime().exec(cmd);
        BufferedReader br = new BufferedReader(new InputStreamReader(p.getInputStream()));
        String s = br.readLine();
        while(s!=null){
            System.out.println(s);
            s=br.readLine();
        }
    }
}