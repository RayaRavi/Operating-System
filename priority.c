#include<stdio.h>
void main()
{
    int burst[10],pri[10],wait[10],start[10],finish[10],i,j,temp1,temp2,n,totalwait=0,totalavg=0,totalturn=0;
    float avgwait=0.0,avgturn=0.0;
    printf("Enter n value");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("\nEnter burst time and priority of process %d",i);
        scanf("%d%d",&burst[i],&pri[i]);
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(pri[i]>pri[j])
            {
                temp1=pri[i];
                pri[i]=pri[j];
                pri[j]=temp1;
                temp2=burst[i];
                burst[i]=burst[j];
                burst[j]=temp2;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        if(i==1)
        {
            start[i]=0;
            finish[i]=burst[i];
            wait[i]=start[i];
        }
        else
        {
            start[i]=finish[i-1];
            finish[i]=start[i]+burst[i];
            wait[i]=start[i];
        }
    }
    printf("\n Burst priority start wait finish\n");
    for(i=1;i<=n;i++)
    {
        printf("%5d%8d%5d%4d%6d\n",burst[i],pri[i],start[i],wait[i],finish[i]);
    }
    for(i=1;i<=n;i++)
    {
        totalwait+=wait[i];
        totalturn+=finish[i];
    }
    avgwait=totalwait/n;
    avgturn=totalturn/n;
    printf("\nAverage waiting time = %f\nAverage turn over time = %f\n",avgwait,avgturn);
}

/*

Output:

/tmp/SQ22cGioZJ.o
Enter n value3
Enter burst time and priority of process 1
24 3
Enter burst time and priority of process 2
3 2
Enter burst time and priority of process 3
3 1
Burst priority start wait finish
   24       3    0   0    24
    3       2   24  24    27
    3       1   27  27    30

Average waiting time = 17.000000
Average turn over time = 27.000000

*/