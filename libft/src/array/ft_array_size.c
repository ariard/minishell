/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 19:15:25 by ariard            #+#    #+#             */
/*   Updated: 2017/02/28 14:48:47 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

size_t	ft_array_size(char **array)
{
	size_t		size;

	if (!array || !*array)
		return (0);
	size = 0;
	while (*array++)
		size++;
	return (size);
}
