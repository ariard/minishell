/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 23:15:27 by ariard            #+#    #+#             */
/*   Updated: 2017/01/09 18:08:09 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

char		**ft_strsplitptr(char *str, int (*is)(int c))
{
	char	**array;
	char	**tmp;

	if (!str)
		return (NULL);
	array = ft_memalloc(ft_count_words_ptr(str, is) * sizeof(char *) + 1);
	tmp = array;
	while (*str)
	{
		while (*str && (is)((int)*str) == 1)
			str++;
		*array = ft_strduptr(str, is);
		str += ft_strlen(*array) + 1;
		array++;
	}
	*array = 0;
	return (tmp);
}
