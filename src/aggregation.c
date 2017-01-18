/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aggregation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 21:09:05 by ariard            #+#    #+#             */
/*   Updated: 2017/01/18 22:24:58 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			ft_input_aggregation(char *aggregation)
{
	int		n;
	int		word;

	n = ft_get_first_fd(aggregation);
	word = ft_get_last_fd(aggregation);
	if (n == -1)
		n = 1;
	if (word == -1)
		return (ft_ambiguous_error(aggregation));
	else if (word == -2)
		close(n);
	else if (read(word, NULL, 0) == -1)
		return(ft_bad_fd_error(word));
	else
		dup2(word, n);
	return (1);
}

static int			ft_output_aggregation(char *aggregation)
{
	int		n;
	int		word;

	n = ft_get_first_fd(aggregation);
	word = ft_get_last_fd(aggregation);
	if (n == -1)
		n = 1;
	if (word == -1)
		return (ft_ambiguous_error(aggregation));
	else if (word == -2)
		close(n);
	else if (read(word, NULL, 0) == -1)
		return(ft_bad_fd_error(word));
	else
		dup2(n, word);
	return (1);
}

int			ft_execute_aggregation(char **args)
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
		if (*last == '<')
			return (ft_output_aggregation(tmp));
		if (*last == '>')
			return (ft_input_aggregation(tmp));
		last++;
	}
	return (0);
}
