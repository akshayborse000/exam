#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

void timepass()
{
int i;
	for(i=0;i<100000;i++)
	{
		printf(" \b");
	}
}

int main()
{
int i,pipe_ptr;
pid_t pid;
char file[20];

system("mkfifo pipe_name");
pipe_ptr=open("pipe_name",O_RDWR);


for(i=0;i<5;i++)
{

	pid=fork();
	if(pid<0)
	{
		printf("\nUnable to create process replication \n");
		close(pipe_ptr);
		exit(0);
	}
	
	else if(pid>0)
	{
		printf("\nWriter process. ID = %d\n",getpid());
		
		sprintf(file," Data %d ",i);
		write(pipe_ptr,file,20);
		timepass();
		timepass();		
				
	}

	else if(pid==0)
	{
		printf("Reader process. ID = %d\n",getpid());
		read(pipe_ptr,file,20);
		printf("%s\n",file);
		timepass();
		return 0;
	}

}

close(pipe_ptr);
return 0;
}
