/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_operator3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 20:08:05 by ariard            #+#    #+#             */
/*   Updated: 2017/01/25 20:45:48 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_isfddir(char **args)
{
	char	*last;

	if (!args || !*args)
		return (-1);
	while (*(args + 1))
		args++;
	last = *args;
	while (ft_isdigit(*last++) == 1);
	if (!*last)
		return (1);
	return (0);
}
