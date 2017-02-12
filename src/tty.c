/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tty.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:03:59 by ariard            #+#    #+#             */
/*   Updated: 2017/01/31 16:24:53 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

struct termios		*ft_tty_raw(int fd)
{
	struct termios	buf;
	struct termios	*old_termios;

	old_termios = ft_memalloc(sizeof(struct termios));
	tcgetattr(fd, old_termios);
	buf = *old_termios;
	buf.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	buf.c_iflag &= ~(BRKINT | ICRNL | ISTRIP | IXON);
	buf.c_cflag &= ~(CSIZE | PARENB);
	buf.c_cflag &= ~(OPOST);
	buf.c_cc[VMIN] = 1;
	buf.c_cc[VTIME] = 0;
	tcsetattr(fd, TCSADRAIN, &buf);
	return (old_termios);
}

int				ft_tty_reset(int fd, struct termios *old_termios)
{
	(void)fd;
	tcsetattr(fd, TCSAFLUSH, old_termios);
	free(old_termios);
	old_termios = NULL;
	return (0);
}

int			ft_puterm(int c)
{
	write(1, &c, 1);
	return (1);
}

int				ft_init_term_data(void)
{
	char		*tname;
	char		buf_struct[2048];

	tname = getenv("TERM");
	if (!tname)
		return (-1);
	tgetent(buf_struct, tname);
	return (1);
}	
