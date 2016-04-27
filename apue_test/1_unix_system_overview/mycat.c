#include "apue.h"
#define BUFFSZIE	4096

int main(void)
{
    int n;
    char buf[BUFFSZIE];

    while ((n = read(STDIN_FILENO, buf, BUFFSZIE)) > 0)
	if (write(STDOUT_FILENO, buf, n) != n)
	    err_sys("write error");

    if (n < 0)
	err_sys("read error");

    exit(0);
}
