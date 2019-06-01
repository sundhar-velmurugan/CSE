import java.rmi.Naming;
import java.rmi.registry.LocateRegistry;

public class Server{

	public static void main(String[] args)throws Throwable{
        LocateRegistry.createRegistry(4500);
		Square skeleton = new RemoteSquare();
		Naming.rebind("rmi://localhost:4500/square",skeleton);
		System.out.println("Server is ready");		

	}
}
