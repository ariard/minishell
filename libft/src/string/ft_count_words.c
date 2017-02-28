/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:27:02 by ariard            #+#    #+#             */
/*   Updated: 2017/02/27 20:48:26 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

size_t		ft_count_words(char *str, int c)
{
	size_t	len;
	int		in_word;

	len = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != c && in_word == 0)
		{
			len++;
			in_word++;
		}
		if (*str == c)
			in_word = 0;
		str++;
	}
	return (len);
}
