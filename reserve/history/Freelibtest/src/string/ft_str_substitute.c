/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_substitute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:40:07 by ariard            #+#    #+#             */
/*   Updated: 2017/01/15 16:18:15 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

char	*ft_str_substitute(char *str, char c, char n)
{
	char	*tmp;

	tmp = str;
	while (*str)
	{
		if (*str == c)
			*str = n;
		else
			str++;
	}
	return (tmp);
}
