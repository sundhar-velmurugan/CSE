import java.net.DatagramSocket;
import java.net.DatagramPacket;

public class ex3b{
    public static void main(String []args) throws Exception{
        DatagramSocket ds = new DatagramSocket(2000);
        byte [] s = new byte[100];
        while(true){
            DatagramPacket dp = new DatagramPacket(s, s.length);
            ds.receive(dp);
            byte []data = dp.getData();
            String res = new String(data);
            System.out.println(res);
        }
    }
}