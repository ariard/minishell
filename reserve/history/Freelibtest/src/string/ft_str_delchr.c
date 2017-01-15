/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 17:38:29 by ariard            #+#    #+#             */
/*   Updated: 2017/01/15 16:07:46 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

int			ft_str_delchr(char *str, int pos)
{
	char	*tmp;

	if (!str)
		return (0);
	tmp = ft_strnew(ft_strlen(str) - 1);
	ft_strncpy(tmp, str, pos);
	ft_strcat(tmp, &str[pos + 1]);
	ft_bzero(str, ft_strlen(str));
	ft_strcpy(str, tmp);
	ft_strdel(&tmp);
	return (1);
}
