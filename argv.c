#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * argv()
{
    char *IP;
    IP = (char *)malloc(20);
    strcpy(IP,"192.168.2.186");
    return IP;
}

int main()
{
    char * IP;
    char test[20] = "I am testing";
    int len;
    IP = argv();
    /*
    scanf("%s",test);
    fgets(test,sizeof(test),stdin);
    len = strlen(test);
    test[len-1] = 0;
    */
    printf("%s\n%s\n",IP,test);
    if(strcmp(test,"I am testing")==0)
    {
	printf("success\n");
    }
    //argv();
    free(IP);
    return 0;
}
