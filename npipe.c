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
int i=0,pipe_ptr,r,w,j=0,n;
pid_t writer,reader;
char file[20];

system("mkfifo pipe_name");
pipe_ptr=open("pipe_name",O_RDWR);

printf("Enter the number of reader ");
scanf("%d",&r);
printf("Enter the number of writer ");
scanf("%d",&w);
//r=w=5;
while(i<r||j<w)
{
	n=rand();
	if(n%2==0&&i<r)
	{
		i++;
		reader=fork();
		if(reader==0)
		{
			read(pipe_ptr,file,20);
			printf("i=%d.Child Reader process. ID = %d read %s \n",i,getpid(),file);
			//printf("%s\n",file);
			//timepass();
			return 0;
		}
		else if(reader>0)
		{
			timepass();
		}
	}
	else if(n%2==1&&j<w)
	{
		j++;
		writer=fork();
		if(writer==0)
		{
			printf("\nchild Writer process. ID = %d wrote Data %d\n",getpid(),j);
			timepass();
			sprintf(file," Data %d ",j);
			write(pipe_ptr,file,20);
			timepass();
			//timepass();
			return 0;
		}		
		else if(writer>0)
		{
			timepass();
		}
	}
}

close(pipe_ptr);
return 0;
}
