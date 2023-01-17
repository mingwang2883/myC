#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

/* 冒泡排序 */
/* 1. 从当前元素起，向后依次比较每一对相邻元素，若逆序则交换 */
/* 2. 对所有元素均重复以上步骤，直至最后一个元素 */
/* elemType arr[]: 排序目标数组; int len: 元素个数 */
void bubbleSort(int arr[], int len)
{
    int temp;
    int i, j;
    for (i=0; i<len-1; i++) /* 外循环为排序趟数，len个数进行len-1趟 */
    {
        for (j=0; j<len-1-i; j++) /* 内循环为每趟比较的次数，第i趟比较len-i次 */
        {
            if (arr[j] > arr[j+1]) /* 相邻元素比较，若逆序则交换（升序为左大于右，降序反之） */
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

unsigned int make_a_fortune_day(void)
{
    int week = 0;
    unsigned int date_val;

    time_t t = time(NULL);
    struct tm* stime = localtime(&t);

    week = stime->tm_wday;

    switch(week)
    {
    case 0 :
    case 2 :
    case 4 :
    {
        printf("今天是开奖日,发财密码\n");
    }
        break;

    default:
    {
        int happy_day = 0;

        if(week < 4)
        {
            happy_day = 1;
        }
        else
        {
            happy_day = (7 - week);
        }
        week += happy_day * 24 * 3600;

        printf("%d天后是开奖日,发财密码\n",happy_day);
    }
        break;
    }

    date_val = t + week - (stime->tm_hour * 3600) - (stime->tm_min * 60) - stime->tm_sec;
    date_val += (9 * 60 * 60) + (15 * 60);

    return date_val;
}

int main(void)
{
    int i,j,k;
    int blue_ball = 0;
    int red_ball[6];
    unsigned int date_val;

    memset(red_ball,0,sizeof(red_ball));

    date_val = make_a_fortune_day();
    srand(date_val);

    for(i = 0;i < 5;i++)
    {
        for(j = 0;j < 6;j++)
        {
again:
            red_ball[j] = rand() % 33 + 1;
            if(j > 0)
            {
                for(k = (j - 1);k >= 0;k--)
                {
                    if(red_ball[j] == red_ball[k])
                    {
                        usleep(1000 * 1000);
                        goto again;
                    }
                }
            }
        }

        bubbleSort(red_ball,6);

        printf("红球: ");
        for(j = 0;j < 6;j++)
        {
            printf("%02d ",red_ball[j]);
        }

        blue_ball = rand() % 16 + 1;
        printf("    蓝球: %02d\n",blue_ball);
        sleep(1);
    }

    return 0;
}
