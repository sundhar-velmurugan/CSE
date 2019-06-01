import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class RemoteSquare extends UnicastRemoteObject implements Square{


	public RemoteSquare() throws RemoteException{

		super();
	}

	public int getSquare(int num){
		return num*num;
	}


}
