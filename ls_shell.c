#include <stdio.h>
#include <stdlib.h>

int main()
{
    char l[1024];
    FILE *fp;
    fp = popen("ls","r");
    if(!fp)
    {
	perror("popen");
	exit(-1);
    }
    if(NULL != fp )
    {
	
	while(fgets(l,sizeof(l),fp) != NULL)
	{
	    
	    printf("%s",l);

	}

    }
    //printf("%s",l);

    pclose(fp);

    return 0;

}
