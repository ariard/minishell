#include "Freelibtest/inc/free.h"
#include <unistd.h>
#include <sys/wait.h>

int			main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	int		fd3;
	char	*line;

	(void)argc;
	ft_putstr("yolo");
	fd = open("/dev/stdout", O_RDONLY);
	fd2 = dup(fd);
	fd3 = open(argv[1], O_WRONLY);
	line = 0;
	while ((get_next_line(fd2, &line)))
	{
		ft_putstr(line);
		ft_putstr("\n");
		break;
	}
	ft_putstr("good");
	return (0);
}
