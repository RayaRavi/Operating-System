#include<stdio.h>
typedef struct 
{
    int bno,flag,bn[20];
}
block;
block b[100],b1;
void main()
{
    int rnum();
    int p[30],kk[20],i,n,t,s1,s,r,j,c=1;
    printf("\nEnter number of input files:");
    scanf("%d",&n);
    printf("\nInput the requirements:");
    for(i=1;i<=n;i++)
    {
        printf("\nEnter number of blocks needed for file %d:",i);
        scanf("%d",&p[i]);
    }
    t=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=p[i];j++)
        {
            s=rnum();
            b[s].flag=1;
            b[c].bno=s;
            r=p[i]-1;
            kk[i]=s;
            t=1;
            c++;
        }
    }
    while(r!=0)
    {
        s1=rnum();
        b[s].bn[t]=s1;
        b[s].flag=1;
        b[i].bno=s1;
        r=r-1;
        t=t+1;
    }
    c++;
    printf("\nAllocation\n");
    c=1;
    for(i=1;i<=n;i++)
    {
        printf("\nAllocated for file %d :",i);
        for(j=1;j<=p[i];j++)
        {
            if(j==1)
            {
                printf("%3d",b[c].bno);
                c++;
            }
            else
            {
                printf("------>%3d",b[c].bno);
                c++;
            }
        }
        printf("\n");
    }
}
int rnum()
{
    int k=0,i;
    for(i=1;i<=100;i++)
    {
        k=rand()%100;
        k=k+10;
        if(b[k].flag!=1)
        {
            break;
        }
    }
    return k;
}

/*
Output:
/tmp/SQ22cGioZJ.o
Enter number of input files:3
Input the requirements:
Enter number of blocks needed for file 1:5
Enter number of blocks needed for file 2:4
Enter number of blocks needed for file 3:2
Allocation

Allocated for file 1 : 93------> 96------> 87------>100------>103

Allocated for file 2 : 45------>102------> 59------> 31

Allocated for file 3 : 72------> 37

*/