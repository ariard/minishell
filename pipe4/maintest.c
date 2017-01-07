#include "Freelibtest/inc/free.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int			main(int argc, char **argv)
{
	int		fd[2];
	int		status;
	int		father;
	char	*line;

	(void)argc;
	(void)argv;
	fd[0] = open("/dev/stdout", O_RDONLY);
	fd[1] = open("/dev/stdin", O_WRONLY);

	if (fd[0] < 0)
		ft_putstr("fd0 error");
	if (fd[1] < 0)
		ft_putstr("fd1 error");
	status = pipe(fd);
	if (status == -1)
	   ft_putstr("error");

	father = fork();
	line = 0;
	if (father > 0)
	{
		close(fd[0]);
		close (1);
		dup(fd[1]);
		execve("/bin/ls", argv, NULL);
		close(fd[1]);
	}
	if (father == 0)
	{
		close (fd[1]);
		close(0);
		dup(fd[0]);
		execve("/bin/cat", argv, NULL);
		close(fd[0]);
	}
}
