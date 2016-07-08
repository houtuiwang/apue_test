#include "apue.h"
#include <sys/resource.h>

#define BUFFSIZE	100

static void
sig_intr(int signo)
{
    printf("caught SIGXFSZ\n");
}

int main(void)
{
    int n, m;
    char buf[BUFFSIZE];
    struct rlimit limit;

    if (getrlimit(RLIMIT_FSIZE, &limit))
	err_sys("getrlimit error for RLIMIT_FSIZE");
    if (limit.rlim_cur != RLIM_INFINITY)
	printf("rlim_cur is %10lld \n", limit.rlim_cur);

    limit.rlim_cur = 1024;
    limit.rlim_max = 1024;
    if (setrlimit(RLIMIT_FSIZE, &limit))
	err_sys("setrlimit error for RLIMIT_FSIZE");

    if (getrlimit(RLIMIT_FSIZE, &limit))
	err_sys("getrlimit error for RLIMIT_FSIZE");
    if (limit.rlim_cur != RLIM_INFINITY)
	printf("now rlim_cur is %10lld \n", limit.rlim_cur);

    if (signal(SIGXFSZ, sig_intr) == SIG_ERR) 
	err_sys("signal(SIGXFSZ) error");

    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
	if ((m = write(STDOUT_FILENO, buf, n)) != BUFFSIZE)
	    printf("only write %d \n", m);

    if (n < 0)
	err_sys("read error");

    exit(0);
}
