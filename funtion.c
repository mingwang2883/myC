#include <stdio.h>
#include <math.h>

int funtion(int);

int funtion(int x)
{
    int y;
    if(x > 0)
    {
	y = x+3;
    }else if( x == 0)
    {
	y = 0;
    }else if( x < 0)
    {
	y = pow(x,2) - 1;
    }
    
    return y;
}


int main()
{
    printf("%d\n",funtion(8));
    printf("%d\n",funtion(0));
    printf("%d\n",funtion(-8));

    return 0;
}

