#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>


int main()
{
    pid_t pid;
    int fd[2];
    char buff[64], *cmd = "exit";
    
    if(pipe(fd))
    {
	perror("Create pipe fail!");
	return 0;
    }

    pid = fork();
    if(-1 == pid)
    {
	perror("Create process fail!");
	return 0;
    }else if(0 == pid){
	close(fd[1]);
	printf("wait command from parent!\n");
	while(1)
	{
	    read(fd[0],buff,64);
	    if(strcmp(buff,cmd) == 0)
	    {
		printf("recv command OK\n");
		close(fd[0]);
		exit(0);
	    }
	}
    
    }else{
	printf("Parent process!\n");
	close(fd[0]);
	sleep(2);
	printf("send command to child process!\n");
	write(fd[1],cmd,strlen(cmd)+1);
	close(fd[1]);

    }


    return 0;
}
