#include "Freelibtest/inc/free.h"
#include <termios.h>
#include <sys/types.h>
#include <unistd.h>
#include <term.h>
#include <sys/ioctl.h>
#include <term.h>
#include <stdio.h>

static struct termios	save_termios;
static int				term_saved;

extern NCURSES_EXPORT(char *) tgoto(const char *cstring, int hpos, int vpos);

extern NCURSES_EXPORT(int)	tputs(const char *str, int affcnt, int (*putc)(int));

extern int tgetent(char *bp, const char *name);

extern char *tgetstr(char *name, char **area);

int			tty_raw(int fd)
{
	struct termios	buf;

	if (tcgetattr(fd, &save_termios) < 0)
		return (-1);
	buf = save_termios;
	buf.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	buf.c_iflag &= ~(BRKINT | ICRNL | ISTRIP | IXON);
	buf.c_cflag &= ~(CSIZE | PARENB);
	buf.c_cflag &= ~(OPOST);
	buf.c_cc[VMIN] = 1;
	buf.c_cc[VTIME] = 0;
	if (tcsetattr(fd, TCSADRAIN, &buf) < 0)
		return (-1);
	term_saved = 1;
	return (0);
}


int			tty_reset(int fd)
{
	if (term_saved)
		if (tcsetattr(fd, TCSAFLUSH, &save_termios) < 0)
			return (-1);
	return (0);
}

int			ft_putc(int c)
{
	write(1, &c, 1);
	return (1);
}

int			main(int __unused argc, char __unused **argv)
{
	char	c;
	char	*stream;
	char	buf_struct[100];
	char	*tname;

	tname = getenv("TERM");
	tgetent(buf_struct, tname);
	stream = ft_strnew(1024);
	tty_raw(0);
	c = '\0';
	while (42)
	{
		tputs("ariard-1.0$> ", 1, &ft_putc);
		read(0, &c, 1);
		if (c == '\033')
		{
			read(0, &c, 1);
			if (c == '[')
				read(0, &c, 1);
		}
		ft_putchar(c);
		ft_putchar(10);
		if (c == 'e')
			break;
	}
	tty_reset(0);
	return (0);
}


/*
 ** 	tputs(tgoto("\E[0;0H", 0, 0), 1, &ft_putc);
 */

/*
 **		if (buf_read[1] == 'D')
 **			tputs(tgetstr("le", NULL), 0, &ft_putc);
 **		if (buf_read[1] == 'C')
 **			tputs(tgetstr("nd", NULL), 0, &ft_putc);
 **		if (buf_read[1] == 'A')
 **			tputs(tgetstr("up", NULL), 0, &ft_putc);
 **		if (buf_read[1] == 'B')
 **		tputs(tgetstr("do", NULL), 0, &ft_putc);	
 */
