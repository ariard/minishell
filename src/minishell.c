/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 21:20:36 by ariard            #+#    #+#             */
/*   Updated: 2017/01/03 00:00:30 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			getchar(const int fd, char *c)
{
	int				ret;

	if (-fd < 0 || c == NULL)
		return (-1);
	ret = read(fd, c, 1);
	return (ret);
}

static void			ft_process_stream(char *stream)
{
	ft_lex_analyze(stream);
	//wait;
}

int		main(int __unused ac, char __unused **av, char **ev)
{
	char	*stream;
	char	c;
	t_cht	*sym_tab;
	
	stream = ft_strnew(1024);
	c = '\0';
	sym_tab = ft_gen_symtab(ev); 
	while (42)
	{
		ft_putstr("ariard-0.1$ ");
		while (c != '\n')
		{
			ft_strncat(stream, &c, 1);
			getchar(0, &c);
		}
		if (ft_strcmp(stream, "exit") == 0)
		{
			ft_putstr("exit");
			break;
		}
		ft_process_stream(stream);
		c = '\0';
		ft_bzero(stream, 1024);
	}
}
