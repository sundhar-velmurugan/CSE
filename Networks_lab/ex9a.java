import java.net.DatagramSocket;
import java.net.InetAddress;
import java.io.BufferedReader;
import java.io.FileReader;
import java.net.DatagramPacket;

public class ex9a{
    public static void main(String []args) throws Exception{
        DatagramSocket ds = new DatagramSocket();
        InetAddress address = InetAddress.getLocalHost();
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        String t = br.readLine();
        while(t!=null){
            byte [] temp = new byte[64];
            temp = t.getBytes();
            DatagramPacket dp = new DatagramPacket(temp, temp.length, address, 2000);
            ds.send(dp);
            t = br.readLine();
        }
        br.close();
        ds.close();
    }
}