#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *dirp;

	if(argc != 2)
	{
		fprintf(stderr, "using: ls <dir_name>\n");
		return 1;
	}

	if( (dp = opendir(argv[1])) == NULL )
	{
		perror("opendir");
		return 1;
	}

	while( (dirp = readdir(dp)) != NULL )
		fprintf(stdout, "%s\n", dirp->d_name);

	closedir(dp);
	return 0;
}
