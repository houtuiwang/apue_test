#include "apue.h"

#define BUF_SIZE 1024*1024*1024

static void
sig_intr(int signo)
{
    printf("caught alarm\n");
}

int main(void)
{
    FILE *fp;
    char *ptr;

    if ((ptr = malloc(BUF_SIZE)) == NULL)
	err_sys("malloc error for ptr");

    if (signal(SIGALRM, sig_intr) == SIG_ERR) 
	err_sys("signal(SIGALRM) error");

    alarm(1);

    fp = fopen("test", "w+");
    if (NULL == fp)
	err_sys("fopen error");

    if (fwrite(ptr, 1, BUF_SIZE, fp) != BUF_SIZE)
	err_sys("fwrite error");

    exit(0);
}
