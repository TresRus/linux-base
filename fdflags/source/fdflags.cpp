#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int val;

	if(argc != 2)
	{
		fprintf(stderr, "using: fdflags <file descriptor>\n");
		return 1;
	}

	if( (val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
	{
		perror("fcntl");
		return 1;
	}

	switch(val & O_ACCMODE)
	{
	case O_RDONLY:
		printf("read only");
		break;
	case O_WRONLY:
		printf("write only");
		break;
	case O_RDWR:
		printf("read write");
		break;
	default:
		fprintf(stderr, "unknown access");
		return 1;
	}

	if(val & O_APPEND)
		printf(", append");
	if(val & O_NONBLOCK)
		printf(", nonblock");
#ifdef O_SYNC
	if(val & O_SYNC)
		printf(", synchronize write");
#endif
#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC)
	if(val & O_FSYNC)
		printf(", synchronize write");
#endif
	putchar('\n');

	return 0;
}
