#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct __tm {
    unsigned int tm_sec; /* 秒 – 取值区间为[0,59] */
    unsigned int tm_min; /* 分 - 取值区间为[0,59] */
    unsigned int tm_hour; /* 时 - 取值区间为[0,23] */
    unsigned int tm_ms; /* 毫秒 - 取值区间[0,1000]*/
    unsigned int tm_mday; /* 一个月中的日期 - 取值区间为[1,31] */
    unsigned int tm_mon; /* 月份（从一月开始，0代表一月） - 取值区间为[0,11] */
    unsigned int tm_year; /* 年份，其值等于实际年份 */
}Stm,*pStm;

static time_t mon_yday[2][12] =
{
    {0,31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334},
    {0,31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335},
};

int isleap(int year)
{
    return (year) % 4 == 0 && ((year) % 100 != 0 || (year) % 400 == 0);
}

unsigned long int my_mktime_ms(pStm dt)
{
    unsigned long int result=0;
    int i = 0;

    /* 以平年时间计算的秒数 */
    result  = (dt->tm_year - 1970) * 365 * 24 * 3600;
    result += (mon_yday[isleap(dt->tm_year)][dt->tm_mon] + dt->tm_mday - 1) * 24 * 3600;
    result += (dt->tm_hour - 8) * 3600 + dt->tm_min * 60 + dt->tm_sec;

    /* 加上闰年的秒数 */
    for(i = 1970; i < dt->tm_year; i++)
    {
        if(isleap(i))
        {
            result += 24 * 3600;
        }
    }

    return (result);
}

int main()
{
    unsigned long int sec;
    time_t mytime;
    struct tm *info;
    Stm my_tm;

    memset(&my_tm,0,sizeof(my_tm));
    time(&mytime);
    info = localtime(&mytime);

    printf("year: %d\n",info->tm_year);

    my_tm.tm_year = info->tm_year + 1900;
    my_tm.tm_mon = info->tm_mon;
    my_tm.tm_mday = info->tm_mday;
    my_tm.tm_hour = info->tm_hour;
    my_tm.tm_min = info->tm_min;
    my_tm.tm_sec = info->tm_sec;

    sec = my_mktime_ms(&my_tm);

    printf("%ld\n",sec);
    printf("%s\n",asctime(info));

    return 0;
}
