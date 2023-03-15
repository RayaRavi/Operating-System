#include<stdio.h>
#include<sys/types.h>
main()
{
    int pid,i=0;
    pid=fork();
    if(pid==0)
    {
        printf("\n child process started\n");
        for(i=0;i<10;i++)
            printf("\n%d",i);
            printf("\n child process ends");
    }
    else
    {
        printf("\n parent process starts");
        wait(0);
        printf("\n parent process ends");
       
    }
}
