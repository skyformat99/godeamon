/*
 * Copyright (C) 2018  Kevin Zhu
 * Direct questions, comments to  <ipandtcp@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include "godeamon.h"


int godeamon()
{
	int	fd;

	switch (fork()) {
	case -1: 
		return ERR_FORK;

	case 0:
		break;

	default:
		exit(0);
	}

	if(setsid() == -1) {
		return ERR_SETSID;
	}

	signal(SIGCHLD, SIG_IGN);
        signal(SIGHUP, SIG_IGN);

	switch (fork()) {
	case -1: 
		return ERR_FORK;

	case 0:
		break;

	default:
		exit(0);
	}
	
	umask(0);

	if (chdir("/") == -1) {
		return ERR_CHDIR;
	}

	fd = open("/dev/null", O_RDWR); 
	if (fd == -1) { 
		return ERR_OPEN;
	}

	if (dup2(fd, STDIN_FILENO) == -1) {
		return ERR_DUP2;
	}

	if (dup2(fd, STDOUT_FILENO) == -1) {
		return ERR_DUP2;
	}

#if 0
	if (dup2(fd, STDERR_FILENO) == -1) {
		return ERR_DUP2;
	}

	for(int fd, fd = getdtablesize(); fd >= 0; fd--){
		close(fd);
	}
#endif
	if (fd > STDERR_FILENO) { 
		if (close(fd) == -1 ) {
			return ERR_CLOSE;
		}
	}
	return OK;
}

