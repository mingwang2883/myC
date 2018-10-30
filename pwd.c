#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    FILE *fd;
    int len;
    char buf[100] = "hello world!";
    char P[20];
    fp = popen("pwd","r");
    if(fp == NULL)
    {
	perror("fp");
	exit -1;
    }
    fgets(P,sizeof(P),fp);
    len = strlen(P);
    P[len-1] = 0;
    
    strcat(P,"/test");
    fd = fopen(P,"w");
    if(fd == NULL)
    {
	perror("fd");
	return -1;
    }
    len = strlen(buf);
    fwrite(buf,sizeof(char),len,fd);
    fwrite("\r\n",sizeof(char),2,fd);
    
    printf("%s\n",P);
    
    pclose(fp);
    fclose(fd);
    return 0;

}
