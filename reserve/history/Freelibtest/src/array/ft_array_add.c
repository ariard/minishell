/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 19:09:31 by ariard            #+#    #+#             */
/*   Updated: 2017/01/09 22:59:50 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include <stdio.h>

char			**ft_array_add(char **array, char *string)
{
	char		**new;
	char		**tmp;
	int			size;

	if (!array || !string)
		return (NULL);
	size = ft_array_size(array);
	new = ft_memalloc(sizeof(char *) * (size + 1) + 1);
	tmp = new;
	while (*array)
		*new++ = ft_strdup(*array++);
	*new++ = ft_strdup(string);
	*new = 0;
	return (tmp);
}
