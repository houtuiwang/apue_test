#include "apue.h"

int globvar = 6;	/* externel variable in initialized data */

int main(void)
{
    int var;	/* automatic variable on the stack */
    pid_t pid;

    var = 88;
    printf("before fork\n");	/* we don't flush stdout */

    if ((pid = vfork()) < 0) {
	err_sys("vfork error");
    } else if (pid == 0) {	/* child */
	globvar++;	/* modify parent's vairables */
	var++;
	_exit(0);	/* child terminates */
    }

    printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar,
	    var);

    exit(0);
}
