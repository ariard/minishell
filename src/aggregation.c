/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aggregation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 21:09:05 by ariard            #+#    #+#             */
/*   Updated: 2017/01/30 00:19:15 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			ft_input_aggregation(char *aggregation, t_info *info)
{
	int		n;
	int		word;

	(void)info;
	n = ft_get_first_fd(aggregation);
	word = ft_get_last_fd(aggregation);
	if (n == -1)
		n = 1;
	if (word == -1)
	{
		close(n);
		return (ft_ambiguous_error(aggregation));
	}
	else if (word == -2)
		close(n);
	else
		dup2(n, word);
	return (1);
}

static int			ft_output_aggregation(char *aggregation, t_info *info)
{
	int		n;
	int		word;

	(void)info;
	n = ft_get_first_fd(aggregation);
	word = ft_get_last_fd(aggregation);
	if (n == -1)
		n = 1;
	if (word == -1)
	{
		close(n);
		return (ft_ambiguous_error(aggregation));
	}
	else if (word == -2)
		close(n);
	else
		dup2(word, n);
	return (1);
}

int			ft_execute_aggregation(char **args, t_info *info)
{
	char	*last;
	char	*tmp;

	if (!args || !*args)
		return (-1);
	while (*(args + 1))
		args++;
	last = *args;
	tmp = last;
	while (*last)
	{
		if (*last == '>')
		{
			ft_strdel(&(*args));
			return (ft_output_aggregation(tmp, info));
		}
		if (*last == '<')
		{
			ft_strdel(&(*args));
			return (ft_input_aggregation(tmp, info));
		}
		last++;
	}
	return (0);
}
