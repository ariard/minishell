/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 22:45:57 by ariard            #+#    #+#             */
/*   Updated: 2016/11/23 16:40:30 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

static size_t		ft_wo(char const *s, char c)
{
	size_t			len;

	len = 0;
	if (*s != c)
		len++;
	while (*s)
	{
		if (*s == c && *(s + 1) != c)
			len++;
		s++;
	}
	return (len);
}

static size_t		ft_len_c(char const *s, char c)
{
	size_t			len;

	len = 0;
	while (*s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static void			ft_copy(char **tab, size_t i, char const *s, char c)
{
	size_t			j;

	j = 0;
	while (*s != c)
	{
		tab[i][j] = *s;
		s++;
		j++;
	}
	tab[i][j] = '\0';
}

static	int			ft_check_one(char const *s, char const *tmp)
{
	size_t			len1;
	size_t			len2;

	len1 = ft_strlen(tmp);
	len2 = ft_strlen(s);
	if (len1 == len2)
		return (1);
	else
		return (0);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t			i;
	char			**tab;
	char const		*tmp;

	if (!s || !c)
		return (NULL);
	i = 0;
	tmp = s;
	if (!(tab = (char **)malloc(sizeof(char *) * (unsigned long)ft_wo + 1)))
		return (NULL);
	while (*s)
	{
		if ((*(s - 1) == c && *s != c) || ((ft_check_one(s, tmp)) && *s != c))
		{
			if (!(tab[i] = (char *)malloc(sizeof(char) * ft_len_c(s, c) + 1)))
				return (NULL);
			ft_copy(tab, i, s, c);
			s++;
			i++;
		}
		else
			s++;
	}
	tab[i] = NULL;
	return (tab);
}
