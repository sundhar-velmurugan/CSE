import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Input2{
    public static void main(String []args) throws Exception{
        BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
        //int a = b.read();
        String s = b.readLine();
        System.out.println("String : "+s);
    }
}