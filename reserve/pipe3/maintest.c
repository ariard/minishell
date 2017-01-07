#include "Freelibtest/inc/free.h"
#include <unistd.h>

int			main(int argc, char **argv)
{
	int		fd;

	(void)argc;

	fd = open("./test", O_RDWR);
	close (1);
	dup(fd);
	execve("/bin/ls", argv, NULL); 
	return (0);
}
