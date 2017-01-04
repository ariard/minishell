#include <unistd.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	(void)argc;
	printf("%d", access(argv[1], X_OK));
	return (0);
}	
