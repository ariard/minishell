#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	(void)ac;

	pid_t	father;

	father = fork();
	if (father > 0)
	{
		wait(0);
		printf("I'M YOUR FATHER");
	}
	if (father == 0)
	{

		execve("/bin/ls", av, NULL);
	}
}
