#include<stdio.h>
struct block
{
    int bno,flag;
};
struct block b[100];
int rnum();
void main()
{
    int p[10],r[10][10],ab[10],i,j,n,s;
    printf("\nInput\nEnter number of files:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("\nEnter size of block %d :",i);
        scanf("%d",&p[i]);
    }
    for(i=1;i<=n;i++)
    {
        s=rnum();
        ab[i]=s;
        for(j=0;j<p[i];j++)
        {
            s=rnum();
            r[i][j]=s;
        }
    }
    printf("\nOutput");
    for(i=1;i<=n;i++)
    {
        printf("\nFile %d\n Block %d contains:",i,ab[i]);
        for(j=0;j<p[i];j++)
        {
            printf("%6d",r[i][j]);
        }
    }
    
}
int rnum()
{
    int k=0,i;
    for(i=1;i<=100;i++)
    {
        k=rand()%100;
        if(b[k].flag!=-1)
            break;
    }
    return k;
}

/*
Output:

/tmp/SQ22cGioZJ.o
Input
Enter number of files:3
Enter size of block 1 :5
Enter size of block 2 :6
Enter size of block 3 :9
Output
File 1
 Block 83 contains:    86    77    15    93    35
File 2
 Block 86 contains:    92    49    21    62    27    90
File 3
 Block 59 contains:    63    26    40    26    72    36    11    68    67

*/