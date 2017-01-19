/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_read4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:19:55 by ariard            #+#    #+#             */
/*   Updated: 2017/01/19 17:03:35 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*int			ft_validheredoc(char *buffer)
{
	char	*tmp;

	tmp = buffer;
	while (*(tmp + 1))
		tmp++;
	if (*tmp == '&' || *tmp == ';' || *tmp == '|' || *tmp == '>')
		tmp--;
	while (*tmp && ft_isspace(*tmp) == 1)
		tmp--;
	while (*tmp && ft_isalnum(*tmp) == 1)
		tmp--;
	while (*tmp && ft_isspace(*tmp) == 1)
		tmp--;
	if (*tmp == '<')
		return (1);
	return (-1);
}*/

int			ft_endheredoc(char c)
{
	if (c == '&' || c == ';' || c == '|' || c == '>')
	   return (1);
	return (0);
}
