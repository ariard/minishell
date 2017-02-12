/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 21:37:06 by ariard            #+#    #+#             */
/*   Updated: 2017/01/31 10:59:12 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int		ft_ambiguous_error(char *last)
{
	while (*last && ft_isdigit(*last) == 1)
		last++;
	while (*last && ft_isalnum(*last) == 0)
		last++;
	ft_putstr_fd("ariard : ", 1);
	ft_putstr_fd(last, 1);
	ft_putstr_fd(": ambiguous redirect\n", 1);
	return (-1);
}

int		ft_bad_fd_error(int word)
{
	ft_putstr_fd("ariard : ", 2);
	ft_putnbr_fd(word, 2);
	ft_putstr_fd(": Bad file descriptor\n", 2);
	return (-1);
}

int		ft_file_error(char *path)
{
	ft_putstr_fd("ariard : ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": Permission denied\n", 2);
	return (-1);
}

char	*ft_buffer_error(void)
{
	ft_putstr_fd("\nariard : command too big", 2);
	return (NULL);
}
