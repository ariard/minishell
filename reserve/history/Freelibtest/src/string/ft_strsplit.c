/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:31:12 by ariard            #+#    #+#             */
/*   Updated: 2017/01/09 18:29:00 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

char		**ft_strsplit(char *str, char c)
{
	char	**array;
	char	**tmp;

	if (!str)
		return (NULL);
	array = ft_memalloc(ft_count_words(str, c) * sizeof(char *) + 1);
	str = ft_str_substitute(str, c, ' ');
	tmp = array;
	while (*str)
	{
		while (*str == ' ')
			str++;
		*array = ft_strduptr(str, &ft_isspace);
		str += ft_strlen(*array) + 1;
		array++;
	}
	*array = 0;
	return (tmp);
}
