#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<stdlib.h>
int main()
{
	int i,t[20],n;
	int responsetime[20];
	printf("Total number of process: ");
	scanf("%d",&n);
	printf("Provide data of the processes\n");
	for(i=0;i<n;i++)
	{
	printf("Response time of P%d (in millisec.): ",i);
	scanf("%d",&responsetime[i]);
	if(responsetime[i]<1000)
	{
	t[i]=1;
	}
	else
	{
	t[i]=0;
	}
	}
	printf("Process\t\tResponse Time\tType of process\t\t\tPriority of process");
	for(i=0;i<n;i++)
	{
	printf("\nP%d\t\t%dms\t\t",i,responsetime[i]);
	if(t[i]==1)
	{
	printf("Interactive process\t\tHigh priority");
	}
	else
	{
	printf("Non_Interactive process\t\tLow priority");
	}
	}
}
