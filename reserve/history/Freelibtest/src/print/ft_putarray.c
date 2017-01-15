/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 13:03:14 by ariard            #+#    #+#             */
/*   Updated: 2017/01/08 14:21:27 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

int				ft_putarray(char **array, int delimiter, int last)
{
	int			ret;

	ret = 0;
	if (!array || !*array)
		return (-1);
	while (*array)
	{
		ret += ft_putstr(*array);
		if (!(*(array + 1)))
			ret += ft_putchar(last);
		else
			ret += ft_putchar(delimiter);
		array++;
	}
	return (ret);
}
