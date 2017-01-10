#include "Freelibtest/inc/free.h"
#include <curses.h>
#include <term.h>
#include <sys/ioctl.h>
#include <stdio.h>

extern int tgetent(char *bp, const char *name);

extern int tgetnum(char *name);

extern int tgetflag(char *name);

extern char *tgetstr(char *name, char **area);

extern NCURSES_EXPORT(char *) tgoto(const char *cstring, int hpos, int vpos);

char *BC;

char *UP;

int			main(int __unused argc, char __unused **argv)
{


/*
** Open a term database
*/
/*
	char	*tname;
	char	buffer[2048];
	int 	success;

	tname = getenv("TERM");
	success = tgetent(buffer, tname);
	if (success < 0)
		ft_putstr("fail to get term description\n");
	if (success == 0)
		ft_putstr("not accessible\n");
	if (success > 0)
	{
		ft_putstr("ok database");
		ft_putchar(10);
	}
*/
/*
** Initialization
*/
	char	buffer[100];

	ioctl(0, _IOW('t', 125, sizeof(int)), (0x00200000>>16));
	ioctl(0, _IOW('t', 10, 8), OPOST);
	ft_bzero(buffer, 100);
	while (1)
	{
		read(0, buffer, 1);
		ft_putstr(buffer);
		if (buffer[0] == 'e')
			break;
	}


/*
** Non-canonical mode
*/



/*
** Get columns size
*/

/*		int		col;
		int		hght;

		col = tgetnum("co");
		hght = tgetnum("li");

		printf("lim : %d %d\n", col, hght);
*/
/*
** Terminal initialization
*/

/*		char			*name_term;
		struct termios	*term;

		term = ft_memalloc(sizeof(struct termios));
		if ((name_term = getenv("TERM")) == NULL)
			return (-1);
		if (tgetent(NULL, name_term) < 0)
			return (-1);
		if (tcgetattr(0, term) == -1)
			return (-1);

		char			buffer[3];

		while (1)
		{
			read(0, buffer, 3);
			if (buffer[0] == 0x4c)
				printf("yolo");
			if (buffer[0] == 27)
				printf("Fleche\n");
			else if (buffer[0] == 4)
			{
				printf("cltr + d\n");
				return (0);
			}
		}*/
		return (0);
}
