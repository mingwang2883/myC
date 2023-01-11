#include "DefinedPrint.h"
#define DEF_TAG             "backtrace"

#if 1
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <poll.h>
#include <sys/epoll.h>
#include <sys/select.h>
#include <dirent.h>
#include <sys/types.h>
#include <execinfo.h>
#include <sys/types.h>
#include <sys/wait.h>

extern int lib_test(void);

#define BACKTRACE_BUF_SIZE          128

void SigSegv_handler(int signal)
{
    int j, nptrs;
    void *buffer[BACKTRACE_BUF_SIZE];
    char **strings;

    nptrs = backtrace(buffer, BACKTRACE_BUF_SIZE);
    DEF_PRT_INFO(DEF_TAG,"signal_test exit: backtrace() returned %d addresses, sig:%d\n", nptrs, signal);

    switch (signal)
    {
    case SIGFPE: // 8:
        DEF_PRT_INFO(DEF_TAG,"The signal type: Floating point exception!\n");
        break;
    case SIGILL: // 4:
        DEF_PRT_INFO(DEF_TAG,"The signal type: Illegal instruction!\n");
        break;
    case SIGSEGV: // 11:
    {
        char buff[64] = {0x00};

        sprintf(buff,"cat /proc/%d/maps", getpid());
        system((const char*) buff);

        DEF_PRT_INFO(DEF_TAG,"The signal type: Segmentation fault!\n");
    }
        break;
    case SIGBUS: // 7:
        DEF_PRT_INFO(DEF_TAG,"The signal type: Bus error!\n");
        break;
    case SIGABRT: // 6:
        DEF_PRT_INFO(DEF_TAG,"The signal type: Aborted!\n");
        break;
    case SIGTRAP: // 5:
        DEF_PRT_INFO(DEF_TAG,"The signal type: Trace/breakpoint trap!\n");
        break;
    case SIGSYS: // 31:
        DEF_PRT_INFO(DEF_TAG,"The signal type: Bad system call!\n");
        break;
    case SIGTERM: // 15:
        DEF_PRT_INFO(DEF_TAG,"The signal type: Terminated!\n");
        break;
    case SIGQUIT: // 3:
        DEF_PRT_INFO(DEF_TAG,"The signal type: Quit!\n");
        break;
    case SIGKILL: // 9:
        DEF_PRT_INFO(DEF_TAG,"The signal type: Killed!\n");
        break;
    case SIGHUP: // 1:
        DEF_PRT_INFO(DEF_TAG,"The signal type: Hangup!\n");
        break;
    case SIGALRM: // 14:
        DEF_PRT_INFO(DEF_TAG,"The signal type: Alarm clock!\n");
        break;
    case SIGVTALRM: // 26:
        DEF_PRT_INFO(DEF_TAG,"The signal type: Virtual timer expired!\n");
        break;
    case SIGPROF: // 27:
        DEF_PRT_INFO(DEF_TAG,"The signal type: Profiling timer expired!\n");
        break;
    case SIGIO: // 29:
        DEF_PRT_INFO(DEF_TAG,"The signal type: I/O possible!\n");
        break;
    case SIGPIPE: // 13:
        DEF_PRT_INFO(DEF_TAG,"The signal type: Broken pipe!\n");
        break;
    case SIGXCPU: // 24:
        DEF_PRT_INFO(DEF_TAG,"The signal type: CPU time limit exceeded!\n");
        break;
    case SIGXFSZ: // 25:
        DEF_PRT_INFO(DEF_TAG,"The signal type: File size limit exceeded!\n");
        break;
    case SIGUSR1: // 10:
        DEF_PRT_INFO(DEF_TAG,"The signal type: User defined signal 1!\n");
        break;
    case SIGUSR2: // 12:
        DEF_PRT_INFO(DEF_TAG,"The signal type: User defined signal 2!\n");
        break;
    default:
        DEF_PRT_INFO(DEF_TAG,"The signal type: Unkown signal:%d!\n", signal);
        break;
    }

    /* The call backtrace_symbols_fd(buffer, nptrs, STDOUT_FILENO)
    would produce similar output to the following: */

    strings = backtrace_symbols(buffer, nptrs);
    if (strings == NULL)
    {
        DEF_PRT_ERR(DEF_TAG,"backtrace_symbols");
        exit(EXIT_FAILURE);
    }

    for (j = 0; j < nptrs; j++)
    {
        DEF_PRT_ERR(DEF_TAG,"%s\n", strings[j]);
    }

    free(strings);
    exit(-1);
}

void test(void)
{
    char buf[4];


    sprintf(buf,"%s",45);

}
#endif

void main(void)
{
//    signal(SIGSEGV, SigSegv_handler);
    signal(SIGILL, SigSegv_handler);
    signal(SIGBUS, SigSegv_handler);
    signal(SIGFPE, SigSegv_handler);
    signal(SIGABRT, SigSegv_handler);
    signal(SIGTRAP, SigSegv_handler);
    signal(SIGSYS, SigSegv_handler);
    signal(SIGTERM, SigSegv_handler);
    signal(SIGQUIT, SigSegv_handler);
    signal(SIGKILL, SigSegv_handler);
    signal(SIGHUP, SigSegv_handler);
    signal(SIGALRM, SigSegv_handler);
    signal(SIGVTALRM, SigSegv_handler);
    signal(SIGPROF, SigSegv_handler);
    signal(SIGIO, SigSegv_handler);
    signal(SIGPIPE, SigSegv_handler);
    signal(SIGXCPU, SigSegv_handler);
    signal(SIGXFSZ, SigSegv_handler);
    signal(SIGUSR1, SigSegv_handler);
    signal(SIGUSR2, SigSegv_handler);

    lib_test();
//    test();


    return;
}
