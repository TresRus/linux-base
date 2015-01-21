#include "../include/fileflags.h"

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void set_fl(int fd, int flags)
{
	int val;

	if( (val = fcntl(fd, F_GETFL, 0)) < 0)
	{
		perror("fcntl");
		return;
	}

	val |= flags;

	if( fcntl(fd, F_SETFL, val) < 0)
	{
		perror("fcntl");
		return;
	}
}

void clr_fl(int fd, int flags)
{
	int val;

	if( (val = fcntl(fd, F_GETFL, 0)) < 0)
	{
		perror("fcntl");
		return;
	}

	val &= ~flags;

	if( fcntl(fd, F_SETFL, val) < 0)
	{
		perror("fcntl");
		return;
	}
}