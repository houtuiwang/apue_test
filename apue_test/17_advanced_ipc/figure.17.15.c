#include "apue.h"
#include <sys/socket.h>

#if defined(SCM_CREDS)	/* BSD interface */
#define CREDSTRUCT	cmsgcred
#define
