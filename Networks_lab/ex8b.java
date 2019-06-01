import java.net.Socket;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.FileWriter;

public class ex8b{
    public static void main (String []args) throws Exception{
        Socket soc = new Socket("localhost", 2000);
        BufferedReader br = new BufferedReader(new InputStreamReader(soc.getInputStream()));
        FileWriter fw = new FileWriter("output.txt");
        String temp = br.readLine();
        int i=1;
        while(temp!=null){
            String t = "Line "+Integer.toString(i)+" :"+temp;
            fw.write(t+"\n");
            temp = br.readLine();
            i++;
        }
        br.close();
        fw.close();
        soc.close();
    }
}