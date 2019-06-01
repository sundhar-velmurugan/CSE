import java.net.Socket;

public class ex10{
	public static void main(String[] args)throws Throwable{
		for(int i=1;i<65535;i++){
			try{
				Socket s = new Socket("localhost",i);
				System.out.println("Active port : "+i);
				s.close();
			
			}catch(Exception e){}
        }
    }
}
