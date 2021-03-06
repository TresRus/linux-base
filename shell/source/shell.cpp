#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

const unsigned int MAXLINE = 1024;

void sig_int(int signo)
{
	printf("interupt\n%% ");
}

int main(int argc, char *argv[])
{
	char buf[MAXLINE];
	pid_t pid;
	int status;

	if( signal(SIGINT, sig_int) == SIG_ERR)
	{
		perror("signal");
		return 1;
	}

	printf("%% ");

	while( fgets(buf, MAXLINE, stdin) != NULL )
	{
		if( buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = 0;

		if( (pid = fork()) < 0 )
		{
			perror("fork");
			return 1;
		}
		else if ( pid == 0 )
		{
			execlp(buf, buf, NULL);
			fprintf(stderr, "can't run %s\n", buf);
			return 127;
		}

		if( (pid == waitpid(pid, &status, 0)) < 0 )
		{
			perror("waitpid");
			return 1;
		}
		printf("%% ");
	}

	return 0;
}
