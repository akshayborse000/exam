#include<stdio.h>

struct process
{
int status;
int p_id;
}proc[10];

int co_id,g_id,number,elect1;

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
	printf("processes \n");
	printf("p_id\tstatus\n");
	for(i=0;i<number;i++)
	{
		printf("%d\t%d\n",proc[i].p_id,proc[i].status);
	}

}

void first_election()
{
	int i,max=-1;
	for(i=0;i<number;i++)
	{
		if(proc[i].status==1&&proc[i].p_id>max)
		{
			max=proc[i].p_id;
		}
	}
co_id=max;
}

void bully(int elect)
{
int i,max=elect,j;
	for(i=elect;i<number;i++)
	{
			if(proc[i].status==1)
			{
				for(j=i+1;j<number;j++)
				{
					printf(" Message from process %d ----> process %d \n",i,j);
				}			
				
				for(j=i+1;j<number;j++)
				{
					if(proc[j].status==1)
					{
						printf(" Acknowledgement from process %d ----> process %d \n",j,i);
						if(max<j)
						max=j;
					}
				}

	
			}
	
	}
co_id=max;
	
}

int main()
{

int i,ch1=1,ch2,crash,act,elect;
input();
first_election();
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
			printf("Co-ordinator crashed. Enter process id to start election \n");
			scanf("%d",&elect);
			bully(elect);
			printf("Co-ordinator is %d\n",co_id);
		}
		display();
		break;

		case 2:
		printf("Enter the p_id of process to be crashed ");
		scanf("%d",&crash);
		proc[crash].status=1;
		//bully();
		display();
		break;
	}
}

return 0;
}
