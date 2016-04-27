#include "apue.h"
#include <fcntl.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main(void)
{
    if (creat("test4.2", 0777) < 0)
	err_sys("creat error for foo");
    exit(0);
}
