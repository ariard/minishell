/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 23:15:27 by ariard            #+#    #+#             */
/*   Updated: 2017/02/26 16:15:04 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

char		**ft_strsplitptr(char *str, int (*is)(int c))
{
	char	**array;
	char	**tmp;
	int		len;

	if (!str)
		return (NULL);
	array = ft_memalloc((ft_count_words_ptr(str, is) + 1) * sizeof(char *));
	tmp = array;
	while (*str)
	{
		while (*str && (is)((int)*str) == 1)
			str++;
		*array = ft_strduptr(str, is);
		len = ft_strlen(*array) + 1;
		while (*str && len--)
			str++;
		array++;
	}
	*array = 0;
	return (tmp);
}
