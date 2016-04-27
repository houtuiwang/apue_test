#include "apue.h"

int dup2(int fd, int fd2)
{
    int fd3=0;


    if (fd2 == fd) {
	return fd2;
    }

    if ((fd3=dup(fd)) < 0)
	err_sys("dup error");
    else {
	if (fd3 > fd2) {
	    close(fd2);
	} else {
	    继续dup直到fd3==fd2，然后返回fd2，同时close之前打开的新fd。
	}
    }
}
