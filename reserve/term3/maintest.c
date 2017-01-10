#include "Freelibtest/inc/free.h"
#include <termios.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <term.h>
#include <sys/ioctl.h>
#include <stdio.h>

extern NCURSES_EXPORT(int)	tputs(const char *str, int affcnt, int (*putc)(int));

extern int tgetent(char *bp, const char *name);

static struct termios	old_termios;


int			ft_puterm(int c)
{
	write(1, &c, 1);
	return (1);
}

int			ft_set_raw_tty(int fd)
{
	struct termios	*new_termios;

	if (tcgetattr(fd, &old_termios) < 0)
		return (-1);
	new_termios = ft_memalloc(sizeof(struct termios));
	new_termios = &old_termios;
	new_termios->c_lflag = ~(ICANON | ECHO | IEXTEN | ISIG);
	new_termios->c_iflag = ~(BRKINT | ICRNL | ISTRIP | IXON);
	new_termios->c_cflag = ~(CSIZE | PARENB);
	new_termios->c_cflag = ~(OPOST);
	new_termios->c_cc[VMIN] = 1;
	new_termios->c_cc[VTIME] = 0;
	if (tcsetattr(fd, TCSADRAIN, new_termios) < 0)
		return (-1);
	return (0);
}

int			reset_tty(int fd)
{
	if (tcsetattr(fd, TCSAFLUSH, &old_termios) < 0)
		return (-1);
	return (0);
}

int			main(int __unused argc, char __unused **argv)
{
	char	*stream;
	char	*tname;
	char	buf_struct[100];
	char	c;

	tname = getenv("TERM");
	tgetent(buf_struct, tname);
	stream = ft_strnew(1024);
	c = '\0';
	ft_set_raw_tty(0);	
	while (42)
	{	
		tputs("ariard-0.1$>", 0, &ft_puterm);
		while (1)
		{
			ft_strncat(stream, &c, 1);
			read(0, &c, 1);
//			ft_putchar(c);
			if (c == 'e')
				break;
		}
		break;
	}
	reset_tty(0);
	return (0);
}
