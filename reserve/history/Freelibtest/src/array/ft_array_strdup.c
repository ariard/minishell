/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_strdup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:44:53 by ariard            #+#    #+#             */
/*   Updated: 2017/01/09 21:54:37 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

char			**ft_array_strdup(char **array)
{
	int			size;
	char		**tab;
	char		**tmp;

	size = ft_array_size(array); 
	tab = ft_memalloc(size * sizeof(char *) + 1);
	tmp = tab;
	while (*array)
		*tab++ = ft_strdup(*array++);
	*tab = 0;	
	return (tmp);
}
