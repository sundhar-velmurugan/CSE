import java.net.DatagramSocket;
import java.net.DatagramPacket;
import java.io.FileWriter;
import java.lang.String;//for trim()

public class ex9b{
    public static void main(String []args) throws Exception{
        DatagramSocket ds = new DatagramSocket(2000);
        FileWriter fw = new FileWriter("output.txt");
        while(true){
            byte[] arr = new byte[64];
            DatagramPacket dp = new DatagramPacket(arr, arr.length);
            ds.receive(dp);
            byte [] temp = dp.getData();
            String t = new String(temp);
            fw.write(t.trim()+"\n");
            fw.flush();
        }
        fw.close();
        ds.close();
    }
}