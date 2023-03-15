#include<stdio.h>
void main()
{
int start[10],burst[10],need[10],execution[10],wait[10],finish[10],turn[10];
int i,ts,n,totaltime=0,totalburst=0;
float totalwait=0.0,totalturn=0.0,totalresp=0.0;
float avgwait=0.0,avgturn=0.0,avgresp=0.0;
clrscr();
printf("Enter number of process");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter process %d burst time",(i+1));
scanf("%d",&burst[i]);
}
printf("Enter time slice");
scanf("%d",&ts);
for(i=0;i<n;i++)
{
need[i]=burst[i];
execution[i]=0;
wait[i]=0;
finish[i]=0;
turn[i]=0;
totalburst=totalburst+burst[i];
}
while(totalburst>0)
{
for(i=0;i<n;i++)
{
if(execution[i]==0)
{
start[i]=totaltime;
}
if(need[i]>ts)

{
execution[i]=execution[i]+ts;
need[i]=need[i]-ts;
totaltime=totaltime+ts;
totalburst=totalburst-ts;
}
else
{
if(need[i]>0)
{
execution[i]=execution[i]+need[i];
totaltime=totaltime+need[i];
wait[i]=totaltime-execution[i];
finish[i]=wait[i]+burst[i];
turn[i]=wait[i]+burst[i];
totalburst=totalburst-need[i];
need[i]=0;
}
}
}
}
printf("\n process burst start wait finish turnaround");
for(i=0;i<n;i++)
{
printf("%7d %5d %5d %5d %4d %6d \n",(i+1),burst[i],start[i],wait[i],finish[i],turn[i]);
}
for(i=0;i<n;i++)
{
totalwait=totalwait+wait[i];
totalturn=totalturn+turn[i];
totalresp=totalresp+start[i];
}
avgwait=totalwait/n;
avgturn=totalturn/n;
avgresp=totalresp/n;
printf("\n Average waiting time %f\n",avgwait);
printf("\n Average turnaround time %f\n",avgturn);
printf("\n Average response time %f\n",avgresp);

}

/*

Output:

/tmp/SQ22cGioZJ.o
Enter number of process3
Enter process 1 burst time24
Enter process 2 burst time3
Enter process 3 burst time3
Enter time slice2
process burst start wait finish turnaround      1    24     0     6   30     30 
      2     3     2     6    9      9 
      3     3     4     7   10     10 

 Average waiting time 6.333333

 Average turnaround time 16.333334

 Average response time 2.000000

*/