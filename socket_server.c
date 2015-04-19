#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void DisplayError(char * ErrorMsg)
{
	puts(ErrorMsg);
	exit(1);
}

void* HandleClient( void * sock)
{
int client_Desc=*(int*)sock;
int TempSockfd,i,con;
printf("in handle\n");
struct sockaddr_in TempSock;
TempSock.sin_family=AF_INET;
TempSock.sin_addr.s_addr=INADDR_ANY;

printf("sock created\n");
for(i=0;i<=10000;i++)
{
	TempSockfd=socket(AF_INET,SOCK_STREAM,0);
	if(TempSockfd<0)
	{
		perror("");
		//exit(1);
		
	}
	TempSock.sin_port=htons(i);
	con=connect(TempSockfd, (struct sockaddr *)&TempSock ,sizeof(TempSock ));
	if(con>=0)
	{
		printf("%d\n",i);
	
	}
	//else
	//printf("%dp\n",i);
	close(TempSockfd);
}
}

int main(int argc,char *argv[])
{
int Server_Desc,Client_Desc;
struct sockaddr_in EchoServerAddr,EchoClientAddr; //address structure
int ServerPort;
int ClientLen;
char buffer[10];
if(argc!=3)
{
	printf("Plese enter correct number of arguments");
	exit(1);
}

ServerPort=atoi(argv[1]);

//create socket for server

if((Server_Desc=socket(AF_INET,SOCK_STREAM,0))<0)
{
	DisplayError("couldnt create socket");
}

//memset(&EchoServerAddr,0,sizeof(EchoServerAddr));
EchoServerAddr.sin_family=AF_INET;
EchoServerAddr.sin_addr.s_addr=inet_addr(argv[2]);
EchoServerAddr.sin_port=htons(ServerPort);


if(bind(Server_Desc,(struct sockaddr*)&EchoServerAddr,sizeof(EchoServerAddr))<0)
{
//DisplayError("couldnt bind");
perror("bind failed. Error");
}

listen(Server_Desc,5);
ClientLen=sizeof(EchoClientAddr);
pthread_t t_id;

while(1)
{
	Client_Desc=accept(Server_Desc,(struct sockaddr*)&EchoClientAddr,&ClientLen);
	if(Client_Desc>0)
	{
		pthread_create(&t_id,NULL,HandleClient,(void*)&Client_Desc);
		pthread_join(&t_id,NULL);
	}
}

close(Server_Desc);

//read(Client_Desc,buffer,5);
//printf("%s",buffer);
return 0;
}
