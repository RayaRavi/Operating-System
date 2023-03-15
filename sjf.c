#include<stdio.h>
void main()
{
    int i,j,burst[10],start[10],finish[10],wait[10],n,temp;
    float totalwait=0.0,totalturn=0.0,avgwait,avgturn;
    printf("Enter number of process");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("\nEnter process %d Burst time:",i);
        scanf("%d",&burst[i]);
    }
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(burst[i]>burst[j])
            {
                temp=burst[i];
                burst[i]=burst[j];
                burst[j]=temp;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        if(i==1)
        {
            start[i]=0;
            finish[i]=burst[i];
            wait[i]=0;
        }
        else
        {
            start[i]=finish[i-1];
            finish[i]=start[i]+burst[i];
            wait[i]=start[i];
        }
    }
    printf("\n Burst start finish wait\n");
    for(i=1;i<=n;i++)
    {
        printf("%5d%5d%6d%4d\n",burst[i],start[i],finish[i],wait[i]);
    }
    for(i=1;i<=n;i++)
    {
        totalwait+=wait[i];
        totalturn+=finish[i];
    }
    avgwait=totalwait/n;
    avgturn=totalturn/n;
    printf("Average waiting time %f\nAverage turn over time %f\n",avgwait,avgturn);
}

/*

Output:

/tmp/SQ22cGioZJ.o
Enter number of process3
Enter process 1 Burst time:27
Enter process 2 Burst time:1
Enter process 3 Burst time:2
Burst start finish wait
    1    0     1   0
    2    1     3   1
   27    3    30   3
Average waiting time 1.333333
Average turn over time 11.333333

*/