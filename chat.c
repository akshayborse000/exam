#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

void main(int argc,char *argv[])
{
//	pid_t flag;
	int pipe;
	int i=0;
	int n;
	char line[100]="";
	system("mkfifo piped");
	pipe=open("piped",O_RDWR);
	
	n=atoi(argv[1]);
	
	while(i<5)
	{
//		flag=fork();
		i++;
		n++;
/*		if(flag<0)
		{
			printf("Error:Unable to fork");
			exit(0);
		}
		else if(flag>0)
		{
			usleep(5000);
		}
		else 
		{
*/			if(n%2==0)//reader
			{
				printf("\nGuest:%d-->>",getpid());
				while(1)
				{
				read(pipe,line,80);
				if(strcmp(line,""))
					break;
				}
				printf("%s\n",line);
				strcpy(line,"");
				usleep(5000);
			}
			else
			{
				printf("\nMyself::");
				gets(line);
				write(pipe,line,80);
				strcpy(line,"");
				usleep(5000);
			}
//			return;
//		}
//		i++;	
	}
	close(pipe);
}
