#include <stdio.h>

int main(int argc, char *argv[])
{
	int c;

	while ( (c = getc(stdin) ) != EOF )
	{
		if( putc(c, stdout) == EOF)
		{
			perror("putc");
			return 1;
		}
	}
	if(ferror(stdin))
	{
		perror("getc");
		return 1;
	}

	return 0;
}
