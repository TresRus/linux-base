#include <stdio.h>
#include <unistd.h>

int glob = 6;
char buf[] = "record in stdout\n";

int main()
{
	int var;
	pid_t pid;

	var = 88;
	if( write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf)-1 )
	{
		perror("write");
		return 1;
	}

	printf("Before call fork\n");

	if( (pid = fork()) < 0 )
	{
		perror("fork");
		return 1;
	}
	else if( pid == 0 )
	{
		glob++;
		var++;
	}
	else
	{
		sleep(2);
	}

	printf("pid = %d, glob = %d, var %d\n", getpid(), glob, var);

	return 0;
}