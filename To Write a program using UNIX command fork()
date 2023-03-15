#include<stdio.h>
#include<sys/types.h>
main()
{
    int pid;
    pid= fork();
    if(pid==0)
    {
        printf("\n I am child");
        printf("\n I am the parent:%d",getppid());
        printf("\n I am the child:%d",getpid());
    }
    else
    {
        printf("\n I am the parent");
        printf("\n I am the parents parent:%d",getppid());
        printf("\n I am the parent:%d",getpid());
    }
}
