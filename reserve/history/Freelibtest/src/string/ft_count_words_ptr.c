/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:26:12 by ariard            #+#    #+#             */
/*   Updated: 2017/01/09 18:07:55 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

size_t		ft_count_words_ptr(char	*str, int (*is)(int c))
{
	size_t	len;
	int		in_word;

	if (!*str)
		return (-1);
	len = 0;
	in_word = 0;
	while (*str)
	{
		if ((is)((int)*str) == 0 && in_word == 0)
		{
			len++;
			in_word++;
		}
		if ((is)((int)*str) == 1)
			in_word = 0;
		str++;
	}
	return (len);
}
