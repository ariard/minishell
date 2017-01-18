/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aggregation2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 21:26:36 by ariard            #+#    #+#             */
/*   Updated: 2017/01/18 22:24:56 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_get_first_fd(char *str)
{
	char	buf[5];
	char	*tmp;
	int		i;

	ft_bzero(buf, 5);
	i = 0;
	tmp = str;
	while (*tmp && ft_isdigit(*tmp) == 1)
	{
		tmp++;
		i++;
	}
	if (i == 0)
		return (-1);
	ft_strncpy(buf, str, i);
	return (ft_atoi(buf));
}

int		ft_get_last_fd(char *str)
{
	char	buf[5];
	char	*tmp;
	int		i;

	ft_bzero(buf, 5);
	i = 0;
	tmp = str;
	while (*tmp && ft_isdigit(*tmp) == 1)
		tmp++;
	while (*tmp && ft_isdigit(*tmp) == 0)
	{
		if (*tmp == '-')
			return (-2);
		tmp++;
	}
	str = tmp;
	while (*tmp && ft_isdigit(*tmp) == 1)
	{
		tmp++;
		i++;
	}
	if (i == 0)
		return (-1);
	ft_strncpy(buf, str, i);
	return (ft_atoi(buf));
}
