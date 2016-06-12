#include "apue.h"
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    DIR *dir;
    int val, fd;
    char buf[10]; /* for save fd */
    pid_t pid;

    dir = opendir("/");
    fd = dirfd(dir);

    if ((val = fcntl(fd, F_GETFD, 0)) < 0)
	    perror("fcntl");
    if (val & FD_CLOEXEC)
	printf("close-on-exec is on\n");
    else
	printf("close-on-exec is off\n");

    val &= ~FD_CLOEXEC;
    fcntl(fd, F_SETFD, val);
    sprintf(buf, "%d\0", fd);

    if ((pid = fork()) < 0)
	perror("fork");
    else if (pid == 0) {
	execl("/home/bob/bin/test8.7_child", "test8.7_child", buf, NULL);
	exit(0);
    }

    return 0;
}
