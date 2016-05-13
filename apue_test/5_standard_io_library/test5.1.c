void mysetbuf(FILE *restrict fp, char *restrict buf)
{
    if (buf == NULL) {  
	if (setvbuf(fp, buf, _IONBF, BUFSIZ) != 0) {  
	    err_sys("setvbuf error!");  
	}  
	printf("no buf\n");  
    } else {  
	if (fp == stderr) {  
	    if (setvbuf(fp, buf, _IONBF, BUFSIZ) != 0) {  
		err_sys("setvbuf error!");  
	    }  
	    printf("no buf\n") ;  
	}else if (fp == stdin || fp == stdout) {  
	    if (setvbuf(fp, buf, _IOLBF, BUFSIZ) != 0) {  
		err_sys("setvbuf error!");  
	    }  
	    printf("line buf\n");  
	} else {  
	    if (setvbuf(fp, buf, _IOFBF, BUFSIZ) != 0) {  
		err_sys("setvbuf error!");  
	    }  
	    printf("full buf\n");  
	}  
    }  
}  
