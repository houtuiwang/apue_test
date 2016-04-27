#include "apue.h"
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if (argc!=3) 
	err_quit("usage: mycp <sourcefile> <destfile>");

    int fds, fdd;

    if ((fds=open(argv[1], O_RDONLY, 0)) < 0)
	err_sys("can't open: %s", argv[1]);

    if ((fdd=open(argv[2], O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR)) < 0)
	err_sys("can't open: %s", argv[2]);

    char buf;
    int n;
    while ((n=read(fds, &buf, 1)) > 0) {
	if (buf != 0)
	    write(fdd, &buf, n);
    }

    if (n < 0)
	err_sys("read error");

    return 0;
}
