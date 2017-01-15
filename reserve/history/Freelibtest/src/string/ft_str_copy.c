/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 20:36:56 by ariard            #+#    #+#             */
/*   Updated: 2017/01/11 21:22:58 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

char		*ft_str_copy(char *str, int begin, int end)
{
	char	*tmp;

	if (!str || end - begin <= 0)
		return (0);
	tmp = ft_strnew(end - begin + 1);
	ft_strncpy(tmp, &str[begin], end - begin);
	return (tmp);
}
