#include "apue.h"
#include <sys/utsname.h>

int main(void)
{
    struct utsname name;
    int ret = 0;

    if ((ret = uname(&name)) < 0)
	err_sys("uname error");
    printf("sysname is %s, nodename is %s, release is %s, version is %s, machine is %s \n", 
	    name.sysname, name.nodename, name.release, name.version, name.machine);
    exit(0);
}
