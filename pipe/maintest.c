#include "Freelibtest/inc/free.h"
#include <fcntl.h>
#include <unistd.h>

int			main(void)
{
	int		fd;
	int		fd2;
	char	*line;
//	int		ret;

	line = 0;
	fd = open("/dev/stdout", O_RDONLY);
	fd2 = open("/dev/stdin", O_WRONLY);
	dup2(fd, fd2);
	close(fd);
	close(fd2);
//	fd2 = open("/dev/stdin", O_RDONLY);
/*	while ((ret = get_next_line(fd2, &line)))
	{
		ft_putstr(line);
		ft_putstr("\n");
	}*/
	return (0);
}

/*
int			main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	int		fd3;
	int		ret;
	int		c;	
	char	*line;

	(void)argc;
	(void)argv;
	c = 10;
	ft_putstr_fd("test", 1);
	line = 0; 
	fd = open("/dev/stdout", O_RDONLY);
	fd3 = dup(fd); 
	fd2 = open("/dev/stdin", O_WRONLY);
	while ((ret = get_next_line(fd3, &line)))
	{
		write(fd2, line, ft_strlen(line));
		write(fd2, &c, 1);
	}
	c = 0;
	write(fd2, &c, 1);	
	close(fd2);
	close(fd);
	return (0);
	fd2 = open("/dev/stdin", O_RDONLY);
	while ((ret = get_next_line(fd2, &line)))
	{
		ft_putstr(line);
		ft_putstr("\n");
	}
	return (0);
}*/
