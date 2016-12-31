/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 21:20:36 by ariard            #+#    #+#             */
/*   Updated: 2016/12/31 01:16:18 by ariard           ###   ########.fr       */
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

int		main(void)
{
	char	*tab;
	char	c;
	
	tab = ft_strnew(1024);
	c = '\0';
	while (42)
	{
		ft_putstr("ariard-0.1$ ");
		while (c != '\n')
		{
			ft_strncat(tab, &c, 1);
			getchar(0, &c);
		}
		ft_putstr(tab);
		ft_putstr("\n");
		c = '\0';
		ft_bzero(tab, 1024);
	}
}
