#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void argv(char *);

void argv(char *str)
{
    int i = 1;
    while(i)
    {
	printf("%s\n",str);
	i--;
    }
    sleep(1);
}


int main()
{
    int n = 8;
    pid_t pid;
    printf("program is starting\n");
    pid=fork();
    switch(pid)
    {
	case -1:
	    exit(0);
	    break;

	case 0:
	    argv("ssss");
	    argv("sss");
	    argv("ss");
	    argv("s");
	    break;

	default:
	    //sleep(n);
		kill(pid,SIGTERM);
    }

    return 0;
}
