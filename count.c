#include <stdio.h>
#include <stdlib.h>

int main()

{
    int shu_zi=0,ci_shu[10]={0},xun_huan=0;
    printf("请输入一个数:");
    scanf("%d",&shu_zi);
    if(shu_zi > 999999999)
    {
	printf("enter error\n");
	exit(-1);
    }
    /*while(shu_zi)
    {
	ci_shu[shu_zi%10]++;
	shu_zi/=10;
    }*/
    //防止输入0时，不运行，所以用do...while
    do{
	ci_shu[shu_zi%10]++;
	shu_zi/=10;
    }while(shu_zi);
    for(xun_huan=0;xun_huan<=9;xun_huan++)
    {
	if(ci_shu[xun_huan])
	{
	    printf("数字%d出现了%d次\n",xun_huan,ci_shu[xun_huan]);
	}
    }
    return 0;
}
