#include <stdio.h>
#include <time.h>


int main()
{
    
    time_t mytime;
    struct tm *info;

    time(&mytime);
    info = localtime( &mytime );

    printf("%s\n",asctime(info));

    return 0;
    
}
