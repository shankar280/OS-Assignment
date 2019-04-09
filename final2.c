#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main()
{
	int i,t[20],n;
	int responsetime[20];
	printf("Total number of process: ");
	scanf("%d",&n);
	printf("Provide data of the processes\n");
