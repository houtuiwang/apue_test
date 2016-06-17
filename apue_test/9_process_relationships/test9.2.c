#include "apue.h"
#include <fcntl.h>

int main()
{
    pid_t pid;
    int result = 0;

    if((pid = fork()) < 0){
	err_sys("fork error");
    }else if(pid == 0){
	int result  = open("/dev/tty", O_RDWR);
	if(result < 0){
	    printf("In child process can't open /dev/tty before setsid()\n");
	}else{
	    printf("In child process can open /dev/tty before setsid()\n");
	}
	printf("In child process,before setsid() the process group id is %d  and process id is %d \n",getpgrp(),getpid());
	if (setsid() < -1) {
	      printf("setsid error\n");
	      exit(1);
	}
	printf("In child process,before setsid() the process group id is %d and process id is %d \n",getpgrp(),getpid());
	result  = open("/dev/tty", O_RDWR);
	if(result < 0){
	    printf("In child process can't open /dev/tty after setsid()\n");
	}
    }else{
	result  = open("/dev/tty", O_RDWR);
	if(result < 0){
	    printf("In parent process can't open /dev/tty after setsid()\n");
	    exit(1);
	}
	printf("In parent process,process group id is %d , process id is %d \n",getpgrp(),getpid());
    }
    return 0;
}
