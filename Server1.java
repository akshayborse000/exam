import java.rmi.*;
import java.rmi.registry.*;

public class Server1
{
	public static void main(String args[])
	{
		String IP,link,add,port;
		IP=args[0];
		link="rmi://";
		add="/add";
		//port=":2001";
		System.setProperty("java.rmi.server.hostname","192.168.1.103");
		try
		{
			Search stub=new SearchRemote();
			
			//Naming.rebind("rmi://127.0.0.1/add",stub);
			Naming.rebind(link+IP+add,stub);
		}
		catch(Exception e)
		{
			System.out.println(e);
			System.out.println("khsajkhsa");
		}
	}
}
