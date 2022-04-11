#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define count 5.0

#if 0
int main()
{
    int i = 0;
    int j;
    for(j = 0;j < 10;j++)
    {
	printf("OK\n");
	if(i++ >= 5)
	{
	   i = 0;
	   printf("success\n");
	}
    }
    return 0;
}
//#else
int a()
{
    int a;
    for(a = 0;a < 5;++a)
    {
	int b = 5;
	float c = 15.64; 
	static float d = 0.9*count;
	printf("%f\n",c - b);
        if(b - a > c)
        {
	    printf("aaaaa\n");
	    c = 0.9*a;
        }
    }
    return 0;
}

int main()
{
    a();
    return 0;
}
#endif

/*
float sort(float b)
{
    static float a = 220.000;
    if(b < a)
    {
	a = b;
    }
    return a;
}


int main()
{
    float a;
    float b;
    while(1)
    {
	scanf("%f",&a);
	b = sort(a);
	printf("min:%.3f\n",b);
	getchar();
    }
    return 0;
}

int main()
{
    int a[3] = {1,5,8};
    int i;
    for(i = 0;i < 3;i++){
	printf("%d\n",a[i]);
    }
    memset(a,0,sizeof(a));
    for(i = 0;i < 3;i++){
	printf("%d\n",a[i]);
    }
    return 0;
}

int main()
{
    int a[5][5];
    int b[5][5];
    int i,j;
    int x;
    x=(x=7,x*4,x+3);

    for(i = 0;i < 5;i++){
	for(j = 0;j < 5;j++){
	    a[i][j] = pow(i + j,2);
	    b[i][j] = j;
	}
    }
    
    for(i = 0;i < 5;i++){
	for(j = 0;j < 5;j++){
	    printf("%d\t",a[i][j]);
	}
	printf("\n");
    }
    printf("%d\n",x);
    return 0;
}

int main()
{
    double score;
    printf("请输入分数：\n");
    scanf("%lf",&score);
    switch((int)(score/10))    //switch((int)score/10)出现严重错误
    {
	case 10:
	case 9:
	    printf("A(最好)\n");
	    break;
	case 8:
	    printf("B(优秀)\n");
	    break;
        case 7:
	    printf("C(良好)\n");
	    break;
        case 6:
	    printf("D(及格)\n");
	    break;
        case 5:
        case 4:
        case 3:
        case 2:
        case 1:
        case 0:
	    printf("E(不及格)\n");
	    break;
        default:
	    printf("Error!\n");
    }
}

int a;

int static_function() {
    
    int i;
    for(i = 0;i < 10;i++) {
	static a = 0;
	a++;
	printf("%d\n",i);
    }
    return 0;
}


int main() {

    static_function();
    printf("a = %d\n",a);
    return 0;
}
*/

#if 0
float lvuk(float va,float vb,float vc) {
    
    float avg,a,b,c;
    float team = 0;
    avg = (va + vb + vc) / 3;
    a = va;
    b = vb;
    c = vc;
    /*
    a = fabs(va - avg);
    b = fabs(vb - avg);
    c = fabs(vc - avg);
    printf("%f\n",a);
    printf("%f\n",b);
    printf("%f\n",c);
    */
    if (a >= b && a >= c) {
	if (b >= c) {
	    team = (a - c) / avg;
	}
	else {
	    team = (a - b) / avg;
	}
	printf("A\n");
    }
    else if (b >= a && b >= c) {
	if (a >= c) {
	    team = (b - c) / avg;
	}
	else {
	    team = (b - a) / avg;
	}
	printf("B\n");
    }
    else if (c >= a && c >= b) {
	if (a >= b) {
	    team = (c - b) / avg;
	}
	else {
	    team = (c - a) / avg;
	}
	printf("C\n");
    }

    return team;
}

int main() {
    
    char str[] = "Hello";
    float a = 180.0,b = 150.0,c = 210.0;
    float res;
    res = lvuk(a,b,c);
    printf("%f\n",res);
    printf("strlen = %d\n",strlen(str));
    printf("sizeof = %d\n",sizeof(str));
    return 0;
}


#endif
/*
int main() {
    int m = 5;
    const int i = 8;
    printf("%d\n",i);
    if (m++ > 5) {
	printf("%d\n",m);	
    }
    else {
	printf("%d\n",--m);
    }
    return 0;
}

int *my_a() {
    int b[2];
    int *c = (int *)malloc(sizeof(b));
    c[0] = b[0];
    c[1] = b[1];
    printf("%d\n",sizeof(b));
    return c;
}

int main() {
    int *d;
    d = my_a();
    printf("%d\n",*d);
    printf("%d\n",*(d+1));
    printf("%d\n",*(d+2));
    printf("%d\n",*(d+3));
    return 0;
}


int main() {
    int a = -123;
    int m =0;
    int b;
    b = (int)(pow(2,31) - 1);
    while(a) {
	m = m * 10 + a % 10;
	a /= 10;
    }
    printf("%d\n",m);
    printf("%d\n",b);
    return 0;
}

*/

int main()
{
    float a = 10.0;
    if (isfinite(a/0.0)) {
	printf("success\n");
    }
    else {
	printf("failed\n");
    }
    return 0;
}
