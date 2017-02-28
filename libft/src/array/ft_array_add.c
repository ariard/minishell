/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 19:09:31 by ariard            #+#    #+#             */
/*   Updated: 2017/02/28 14:57:53 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include <stdio.h>

char			**ft_array_add(char **array, char *string)
{
	char		**new;
	char		**tmp;
	char		*tmp2;
	char		**tmp3;
	int			size;

	if (!string)
		return (NULL);
	if (!array)
		array = NULL;
	size = ft_array_size(array);
	new = ft_memalloc(sizeof(char *) * (size + 1) + 1);
	tmp = new;
	tmp3 = array;
	while (array && *array)
	{
		tmp2 = *array;
		*new++ = ft_strdup(*array++);
		ft_strdel(&tmp2);
	}
	free(tmp3);
	*new++ = ft_strdup(string);
	*new = 0;
	return (tmp);
}
