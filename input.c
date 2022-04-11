#include <stdio.h>
#include <math.h>
#include <time.h>

# if 0
int main()
{
    int a,b;
    a = 0;
    scanf("%d",&b);
    while(a++ < 10)
    {
	b = b + 1;
	printf("%d ",b);

    }
    printf("\n");
    return 0;

}
#endif

int main()
{
    char ch[2];
    printf("Please enter:\n");
loop:scanf("%s",ch);
    if(ch[1]!='\0')
    {
	printf("Please enter a single letter\n");
	goto loop;
    }
    else if(ch[0] >= 'A' && ch[0] <= 'Z')
    {
        printf("input success\n");
    }else{
        printf("input failure\n");
	printf("again\n");
        getchar();
        goto loop;
    }
    return 0;
}
