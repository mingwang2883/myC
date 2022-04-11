#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char *IP_funtion()
{
    FILE *fp;
    int len;
    char *IP_get;
    char IP[20];
    //char AP[20] = "192.168.2.186";
    fp = popen("ifconfig | grep \"Bcast:\" | awk -F \"inet addr:\" '{print $2}' | awk '{print $1}'","r");
    if(!fp)
    {
	perror("popen");
	exit(-1);
    }
    fgets(IP,sizeof(IP),fp);
    len = strlen(IP);
    IP[len-1] = 0;
    /*printf("%s\n",IP);

    if(strcmp(IP,AP)==0)
    {
	printf("IP is success\n");
    }else{
	
	printf("error\n");
	
    }
    */
    IP_get = (char *)malloc(sizeof(IP));
    strcpy(IP_get,IP);
    
    pclose(fp);
    return IP_get;
}


int main()
{
    char * IP_use;
    IP_use = IP_funtion();

    printf("%s\n",IP_use);
    if(strcmp(IP_use,"192.168.2.186") == 0)
    {
	printf("success\n");
    }

    free(IP_use);

    return 0;

}
