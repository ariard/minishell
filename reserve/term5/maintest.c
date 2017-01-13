#include "Freelibtest/inc/free.h"
#include <sys/ioctl.h>
#include <stdio.h>

int			main(int __unused argc, char __unused **argv)
{
	struct	winsize w;
	int		size;

	size = 89;
	ioctl(0, TIOCGWINSZ, &w);
	printf("col : %d\n", w.ws_col);
	while (size--)
		printf("a");
	return (0);
}
