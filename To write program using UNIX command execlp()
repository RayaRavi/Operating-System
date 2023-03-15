#include<stdio.h>
#include<sys/types.h>
main()
{
    int pid;
    pid= fork();
    if(pid==0)
    {
        printf("\n fork program started");
        execlp("/bin/ls","ls",NULL);
    }
    else
    {
        printf("\n end");
       
    }
}

