import java.rmi.*;

public class Client1
{
	public static void main(String args[])
	{
	int sum;
	String IP,link,add,port;
	IP=args[0];
	link="rmi://";
	add="/add";
	port=":2001";
	//NLKDNVLnskfdnknsfdk
		try
		{
			
			Search stub=(Search)Naming.lookup(link+IP+add);
			//Search stub=(Search)Naming.lookup("rmi://127.0.0.1/add");
			sum=stub.addition(Integer.parseInt(args[2]),Integer.parseInt(args[1]));
			System.out.println(sum);
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
}
