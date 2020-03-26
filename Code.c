#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>


int i,j,k,n;
int avg[10],burst[10],wait[10],ta[10];
void waitingtime();
void avgwaittime();
void tatime();
void avgtatime();
void tottime();





void waitingtime()
{
	int temp=0;
	printf("Waiting time of process p1 is:2");
	for(i=1;i<n;i++)
	{
		
		for(j=0;j<i;j++)
		{
			temp+=burst[j];
			
		}
		temp+=avg[0];
		printf("\nWaiting time of process p%d:%d",i+1,temp-avg[i]+2);
		wait[i]=temp-avg[i]+2;
		temp=0;
		
	}
}
void avgwaittime()
{
	int avgg=0;
	for(i=0;i<n;i++)
	{
		avgg+=wait[i];
	}
	printf("\nAverage waiting time is:%d",avgg/n);
	
}
void tatime()
{
	for(i=0;i<n;i++)
	{
		printf("\nTurnAroundTime of the process p%d is:%d",i+1,wait[i]+burst[i]);
		ta[i]=wait[i]+burst[i];
	}
	
}
void avgtatime()
{
	int	avgg=0;
	for(i=0;i<n;i++)
	{
		avgg+=tat[i];
	}
	printf("\nAverage TAT is:%d",avgg/n);
	
}
void tottime()
{
	int ttime=0,extra;
	for(i=0;i<n;i++)
	{
		ttime+=burst[i];	
	}
	extra=2*(n-1);
	ttime+=extra;
	printf("\nThe total time taken to process the given process's is:%d",ttime);
	
}
 void main()
 {
 	int k;
 	printf("\nEnter the number of requirements:\t");
 	scanf("%d",&n);
 	for(i=0;i<n;i++)
 	{
 		printf("Enter the arival time of process p%d: \t",i+1);
		scanf("%d",&k);
		if(k==0)
		{
		printf("zero not allowed\n");
		printf("Re-enter the arrival time:\t");
		scanf("%d",&avg[i]);
		}
		else
			avg[i]=k;
		printf("Enter the burst time:\t");
		scanf("%d",&burst[i]);
		
	}
	int j,temp=0;
	wait[0]=0;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
		
		if(burst[i]>burst[j])
		{
			temp=avg[i];
			avg[i]=avg[j];
			avg[j]=temp;
			
			temp=burst[i];
			burst[i]=burst[j];
			burst[j]=temp;
			
		}
		}
	}
	waitingtime();tatime();avgwaittime();avgtatime();tottime();
	
	
}	
