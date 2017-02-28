/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_inschr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 17:03:19 by ariard            #+#    #+#             */
/*   Updated: 2017/02/27 20:47:09 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

int			ft_str_inschr(char *str, char c, int pos)
{
	char	*tmp;

	if (!str || pos == 0)
		return (0);
	tmp = ft_strnew(ft_strlen(str) + 1);
	ft_strncpy(tmp, str, pos - 1);
	ft_strncat(tmp, &c, 1);
	ft_strcat(tmp, &str[pos - 1]);
	ft_bzero(str, ft_strlen(str));
	ft_strcpy(str, tmp);
	ft_strdel(&tmp);
	return (1);
}
