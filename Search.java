import java.rmi.*;

public interface Search extends Remote
{
	public int addition(int num1,int num2) throws RemoteException;
}
