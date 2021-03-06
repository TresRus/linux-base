#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void)
{
	int fd;

	if( (fd = open("file.hole", O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0 )
	{
		perror("open");
		return 1;
	}

	if( write(fd, buf1, 10) != 10)
	{
		perror("write");
		return 1;
	}

	if( lseek(fd, 16384, SEEK_SET) == -1 )
	{
		perror("lseek");
		return 1;
	}

	if( write(fd, buf2, 10) != 10)
	{
		perror("write");
		return 1;
	}

	close(fd);

	if( (fd = open("file.nohole", O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0 )
	{
		perror("open");
		return 1;
	}

	if( write(fd, buf1, 10) != 10)
	{
		perror("write");
		return 1;
	}

	int curr_pos = 0;

	while( ( curr_pos = lseek(fd, 0, SEEK_CUR) ) != 16384
	    && ( curr_pos != -1 ) )
	{
		if( write(fd, "x", 1) != 1)
		{
			perror("write");
			return 1;
		}
	}
	if(curr_pos == -1)
	{
		perror("lseek");
		return 1;
	}

	if( write(fd, buf2, 10) != 10)
	{
		perror("write");
		return 1;
	}

	close(fd);
}
