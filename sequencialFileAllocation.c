#include<stdio.h>
void main()
{
    int memory[25];
    int i,len,startaddr,flag,endaddr,name;
    for(i=0;i<25;i++)
    {
        memory[i]=0;
        printf("%d",memory[i]);
    }
    printf("\nEnter file name(0 to quit):");
    scanf("%d",&name);
    while(name!=0)
    {
        printf("\nEnter length of file:");
        scanf("%d",&len);
        printf("\n Enter starting location of the file:");
        scanf("%d",&startaddr);
        endaddr=startaddr+len;
        flag=0;
        for(i=startaddr;(i<endaddr && endaddr<25);i++)
        {
            if(memory[i]!=0)
            {
                flag=1;
                printf("\nNo sufficient memory to fill.......");
                break;
            }
        }
        if(flag==0)
        {
            for(i=startaddr;i<endaddr;i++)
            {
                memory[i]=name;
            }
        }
        printf("\nEnter file name(0 to quit):");
        scanf("%d",&name);
    }
    for(i=0;i<25;i++)
    {
        printf("%d",memory[i]);
    }
}


/*

Output:

Enter file name(0 to quit):1
Enter length of file:3
Enter starting location of the file:1
Enter file name(0 to quit):2
Enter length of file:4
Enter starting location of the file:3
No sufficient memory to fill.......
Enter file name(0 to quit):3
Enter length of file:5
Enter starting location of the file:4
Enter file name(0 to quit):0
0111333330000000000000000


*/