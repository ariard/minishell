#include <stdio.h>
#include <unistd.h>

int			main(void)
{
	if (isatty(0))
		printf("stdin is a terminal\n");
	else
		printf("stdin is a file or a pipe\n");
	return (0);
}
