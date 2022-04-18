#ifndef _DEFINED_PRINT_H
#define _DEFINED_PRINT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <malloc.h>

#define DEF_PRT_NORMAL(fmt,...)      printf("\033[40;30m"fmt"\033[0m", ##__VA_ARGS__)
#define DEF_PRT_DBG(TAG,fmt,...)     printf("\033[40;35m""[DEBUG]"TAG":"fmt"\033[0m", ##__VA_ARGS__)
#define DEF_PRT_INFO(TAG,fmt,...)    printf("\033[40;36m""[INFO]"TAG":"fmt"\033[0m", ##__VA_ARGS__)
#define DEF_PRT_WARN(TAG,fmt,...)    printf("\033[40;33m""[WARN]"TAG":"fmt"\033[0m", ##__VA_ARGS__)
#define DEF_PRT_ERR(TAG,fmt,...)     printf("\033[40;31m""[ERROR]"TAG":"fmt"\033[0m", ##__VA_ARGS__)

#ifdef __cplusplus
}
#endif

#endif /* end of _DEFINED_PRINT_H */
