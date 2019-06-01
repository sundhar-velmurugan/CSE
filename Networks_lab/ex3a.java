import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Date;
import java.net.DatagramPacket;

public class ex3a{
    public static void main(String []args) throws Exception{
        DatagramSocket ds = new DatagramSocket();
        InetAddress addr = InetAddress.getLocalHost();
        //int i=0;
        //while(i<15){
        while(true){  
            //Thread.sleep(1000);
            Date d = new Date();
            byte[] s = d.toString().getBytes();
            DatagramPacket dp = new DatagramPacket(s, s.length, addr, 2000);
            ds.send(dp);
            //i++;
        }
    }
}