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
    int hour = 0;
    unsigned int date_val = 0;

    time_t t = time(NULL);
    struct tm* stime = localtime(&t);

    week = stime->tm_wday;
    hour = stime->tm_hour;
    date_val = t;

    if(hour <= 20)
    {
        date_val += (20 - hour) * 60 * 60;
    }
    else if(hour >= 21)
    {
        date_val -= (hour - 21) * 60 * 60;
    }

    switch(week)
    {
    case 0 :
    {
        date_val += 2 * 24 * 3600;
        printf("2天后开奖日,发财密码\n");
    }
        break;

    case 2 :
    {
        date_val += 2 * 24 * 3600;
        printf("2天后开奖日,发财密码\n");
    }
        break;

    case 4 :
    {
        date_val += 3 * 24 * 3600;
        printf("3天后开奖日,发财密码\n");
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
        date_val += happy_day * 24 * 3600;
        printf("%d天后是开奖日,发财密码\n",happy_day);
    }
        break;
    }

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
                        usleep(888);
                        goto again;
                    }
                }
            }
            usleep(8888);
        }

        bubbleSort(red_ball,6);
        printf("红球: ");
        for(j = 0;j < 6;j++)
        {
            printf("%02d ",red_ball[j]);
        }

        blue_ball = rand() % 16 + 1;
        printf("    蓝球: %02d\n",blue_ball);
        usleep(888888);
    }

    return 0;
}
