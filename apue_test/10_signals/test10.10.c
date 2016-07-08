#include "apue.h"
#include <time.h>

int main(void)
{
    int i = 0;
    time_t t;
    struct tm *tmp;

    for ( ; ; ) {
	sleep(60);
	i++;

	if (i == 5) {
	    i = 0;
	    time(&t);
	    tmp = localtime(&t);
	    printf("tm_sec is %d \n", tmp->tm_sec);
	}
    }

    exit(0);
}
