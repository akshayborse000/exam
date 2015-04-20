#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>

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
key_t key=1239,k=0;

struct shmid_ds buffer;
int shm_id,pid,i;
char *array;
char temp_array[20];

for(i=0;i<10;i++)
{
	pid=fork();
	if(pid>0)
	{
		k++;
		printf("\nParent procss id %d\n",getpid());
		shm_id=shmget(key,20*sizeof(char),IPC_CREAT|0777);
		shmctl(shm_id,SHM_LOCK,(struct shmid_ds*)&buffer);
		array=(char *)shmat(shm_id,NULL,0);
		sprintf(array,"%d->%d",getpid(),k);
		shmctl(shm_id,SHM_UNLOCK,(struct shmid_ds*)&buffer);
		timepass();
		timepass();	
	}
	else if(pid==0)
	{
		printf("Child procss id %d",getpid());
		shm_id=shmget(key,20*sizeof(char),0);
		shmctl(shm_id,SHM_LOCK,(struct shmid_ds*)&buffer);
		array=(char *)shmat(shm_id,NULL,0);
		if(array==NULL)
			printf("\nError\n");
		sscanf(array,"%s",temp_array);
		printf("\nArray= %s",temp_array);
		shmctl(shm_id,SHM_UNLOCK,(struct shmid_ds*)&buffer);
		timepass();
		
		return 0;
	}
}
fflush(stdout);
return 0;
}
