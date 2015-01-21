#include <stdio.h>
#include <unistd.h>

const unsigned int BUFFSIZE = 4096;

int main(int argc, char *argv[])
{
	int n;
	char buf[BUFFSIZE];

	while ( (n = read(STDIN_FILENO, buf, BUFFSIZE) ) > 0 )
	{
		if( write(STDOUT_FILENO, buf, n) != n)
		{
			perror("write");
			return 1;
		}
	}
	if(n < 0)
	{
		perror("read");
		return 1;
	}

	return 0;
}
