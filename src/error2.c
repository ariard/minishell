/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 21:37:06 by ariard            #+#    #+#             */
/*   Updated: 2017/01/18 22:24:52 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int		ft_ambiguous_error(char *last)
{
	while (*last && ft_isdigit(*last) == 1)
		last++;
	while (*last && ft_isdigit(*last) == 0)
		last++;
	ft_putstr_fd("ariard : ", 2);
	ft_putstr_fd(last, 2);
	ft_putstr_fd(": ambiguous redirect\n", 2);
	return (-1);
}

int		ft_bad_fd_error(int word)
{
	ft_putstr_fd("ariard : ", 2);
	ft_putnbr_fd(word, 2);
	ft_putstr_fd(": Bad file descriptor\n", 2);
	return (-1);
}
