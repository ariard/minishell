/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 12:12:23 by ariard            #+#    #+#             */
/*   Updated: 2016/11/23 16:39:00 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	char	*tmp;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	new = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!new)
		return (NULL);
	tmp = new;
	while (*s)
	{
		*new = (*f)(i, *s);
		new++;
		s++;
		i++;
	}
	*new = '\0';
	return (tmp);
}
