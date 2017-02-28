/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 13:03:14 by ariard            #+#    #+#             */
/*   Updated: 2017/01/29 20:40:16 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

int				ft_putarray_fd(char **array, int delimiter, int last, int fd)
{
	int			ret;

	ret = 0;
	if (!array || !*array)
		return (-1);
	while (*array)
	{
		ret += ft_putstr_fd(*array, fd);
		if (!(*(array + 1)))
			ret += ft_putchar_fd(last, fd);
		else
			ret += ft_putchar_fd(delimiter, fd);
		array++;
	}
	return (ret);
}
