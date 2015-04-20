#include<stdio.h>
#include<time.h>

struct process
{
	int flag;
	int clock;
	int interval;
}proc[10];
int number;

void timepass()
{
int i;
	for(i=0;i<200000;i++)
	{
		printf(" \b");	
	}
}

void input()
{
	int i;
	printf("Enter the number of processes ");
	scanf("%d",&number);
	for(i=0;i<number;i++)
	{
		printf("Enter the interval of process %d",i);
		scanf("%d",&proc[i].interval);
		proc[i].flag=0;
		proc[i].clock=0;
	}
proc[0].flag=1;
}

void display()
{
	int i,j;
	for(j=0;j<3;j++)
	{
		for(i=0;i<number;i++)
		{
			printf("\nprocess %d.....clock=%d",i,proc[i].clock);
			//sleep(1);
			timepass();
			proc[i].clock=proc[i].clock+proc[i].interval;
		}
	}
	printf("\n display ends\n");
}

void synch()
{
int i,sender_clock,sender_index;
	for(i=0;i<number;i++)
	{
		if(proc[i].flag==1)
		{
			printf("\nprocess %d sends message at clock %d ",i,proc[i].clock);
			sender_clock=proc[i].clock;
			sender_index=i;
		}
	}

	for(i=0;i<number;i++)
	{
		if(proc[i].flag==0)
		{
			printf("\nProcess %d revceives message at clock::%d",i,proc[i].clock);
			timepass();
			if(proc[i].clock<proc[sender_index].clock)
			{
				
				printf("\nSynchronisation of clock of process %d",i);
				printf("\nClock Re-Synchronized to %d",proc[sender_index].clock);
				timepass();
				proc[i].clock=proc[sender_index].clock;
			}
		}
	}
	proc[sender_index].flag=0;
	sender_index++;
	proc[sender_index%number].flag=1;

}

int main()
{
int i;
input();
//display();
for(i=0;i<number;i++)
{
	display();
	synch();
}
}




