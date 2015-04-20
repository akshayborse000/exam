#include<stdio.h>

struct process
{
int status;
int p_id;
}proc[10];

int co_id,g_id,number,elect1,previous;

void input()
{
	int i;
	printf("Enter the number of processes ");
	scanf("%d",&number);

	for(i=0;i<number;i++)
	{
		proc[i].p_id=i;
		printf("Enter status for %d process ",i);
		scanf("%d",&proc[i].status);	
	}

}

void display()
{

int i;
	printf("\n====================================");
	printf("\nprocesses ");
	for(i=0;i<number;i++)
	{
		printf("%d->",proc[i].p_id);
	}
	printf("\nstatus    ");
	for(i=0;i<number;i++)
	{
		printf("%d->",proc[i].status);
	}
	printf("\n====================================\n");

}

int find_max()
{
	int i,max=-1;
	for(i=0;i<number;i++)
	{
		if(proc[i].status==1&&proc[i].p_id>max)
		{
			max=proc[i].p_id;
		}
	}
return max;
}

void ring()
{
int i,j,k;
int max=-1,cycle_complete=0;
int initiator,msg[5],msg_cnt=0;
initiator=i=find_max();
j=i+1;
printf("%d %d",i,j);
while(cycle_complete!=1)
{
	while(proc[j].status==0)
	{
		j++;
		j=j%number;	
	}

	printf("\n%d process sends message to %d process",i,j);
	msg[msg_cnt++]=i;
	printf("Message");

	for(k=0;k<msg_cnt;k++)
		printf("%d ",msg[k]);

	
	i=j;
	j=i+1;
	if(i==initiator)
		cycle_complete++;
	//printf("\nCycle %d\ni %d\nj %d\n",cycle_complete,i,j);
}

for(k=0;k<msg_cnt;k++)
{
	if(max<msg[i])
	max=msg[i];
}
printf("\nMessage is received by initiator that is process %d\n ",initiator);
co_id=initiator;
printf("co ordinator is %d",co_id);
}

int main()
{

int i,ch1=1,ch2,crash,act,elect;
input();
co_id=find_max();
printf("Co-ordinator is %d\n",co_id);
display();

while(ch1!=0)
{
	printf("\n0.Exit\n1.crash process\n2.activate process\n");
	scanf("%d",&ch1);
	switch(ch1)
	{
		case 1:
		printf("Enter the p_id of process to be crashed ");
		scanf("%d",&crash);
		proc[crash].status=0;
		if(proc[co_id].status==0)
		{
			printf("Co-ordinator crashed.\n");
			ring();
		}
		display();
		break;

		case 2:
		printf("Enter the p_id of process to be activated ");
		scanf("%d",&act);
		proc[act].status=1;
		if(act>co_id)
		{
			co_id=act;
			printf("Co-ordinator is %d\n",co_id);			
		}
		display();
		break;
	}
}

return 0;
}
