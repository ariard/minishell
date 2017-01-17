#include "Freelibtest/inc/free.h"
#include <signal.h>

void		sighandler(int signum)
{
	ft_putstr("Signal caught :");
	ft_putnbr(signum);
	exit(1);
}

int			main(int __unused argc, char __unused **argv)
{
	signal(SIGSTOP, sighandler);

	while (1)
	{
		ft_putstr("inifnie looooop\n");
		sleep(1);
	}
	return (0);
}
