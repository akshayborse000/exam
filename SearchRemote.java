import java.rmi.*;
import java.rmi.server.*;

public class SearchRemote extends UnicastRemoteObject implements Search
{
	public SearchRemote() throws RemoteException
	{
		super();
	}
	
	public int addition(int num1,int num2)
	{
		return num1+num2;
	}

}
