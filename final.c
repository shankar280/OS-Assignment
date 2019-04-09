#include<stdio.h>
#include<pthread.h>
#include<stdbool.h>
#include<stdlib.h>
int student[3][4]={0};
void *teacher();
void *st1();
void *st2();
void *st3();
pthread_mutex_t l;
int ch1,ch2;
int r1,r2;

int main()
{	
	printf("\t\t\t---Welcome---\n");
	pthread_mutex_init(&l,NULL);
	
	student[1][1]=1;
	student[2][2]=2;student[3][3]=1;
	pthread_t t_thread;
	pthread_t s_thread;
	printf("Resources Menu: \n\t\tPress '1' for pen\n\t\tPress '2' for paper \n\t\tPress '3' for question_paper \n"); 
	
	while(1)
	{
		if(student[1][4]==1 && student[2][4]==1 && student[3][4]==1){break;}
		pthread_create(&t_thread, NULL, teacher, NULL);
	    pthread_join(t_thread,NULL);
	    
		if((ch1==1 && ch2==2 || ch2==1 && ch1==2 ) && student[3][4]==0)
		{
			pthread_create(&s_thread, NULL, student3, NULL);
			pthread_join(s_thread,NULL);
		}
		else if((ch1==1 && ch2==3 || ch2==1 && ch1==3 ) && student[2][4]==0)
		{
			pthread_create(&s_thread, NULL, student2, NULL);
			pthread_join(s_thread,NULL);
		}
		else if((ch1==2 && ch2==3 || ch2==2 && ch1==3 ) && student[1][4]==0)
		{
			pthread_create(&s_thread, NULL, student1, NULL);
			pthread_join(s_thread,NULL);
		}
		else
		{
			printf("\n\tError (007): try again.. with different choices.\n");
		}
	}
	printf("completed");
	
	
}

void *teacher()
{
	pthread_mutex_lock(&l);
	printf("\nFirst Resource on shared tabel:-\t");
	scanf("%d",&ch1);
	printf("Second Resource on shared tabel:-\t");
	scanf("%d",&ch2);
	pthread_mutex_unlock(&l);
}

void *st2()
{	
	pthread_mutex_lock(&l);
	printf("\nChoices Made = 'pen', 'question_paper'\n");
	student[2][4]=1;
	printf("\n\tStudent 2 has Completed the assignment. \n");
	pthread_mutex_unlock(&l);
}
void *st3()
{	
	pthread_mutex_lock(&l);
	printf("\nChoices Made = 'pen', 'paper'\n");
	student[3][4]=1;
	printf("\n\tStudent 3 has Completed the assignment.\n");
	pthread_mutex_unlock(&l);
}
void *st()
{	
	pthread_mutex_lock(&l);
	printf("\nChoices Made = 'paper', 'question_paper'\n");
	student[1][4]=1;
	printf("\n\tStudent 1 has Completed the assignment.\n");	
	pthread_mutex_unlock(&l);
}
