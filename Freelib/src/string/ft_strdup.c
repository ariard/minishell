/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 20:06:48 by ariard            #+#    #+#             */
/*   Updated: 2016/11/23 16:37:48 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

char	*ft_strdup(const char *s1)
{
	char	*pt;
	int		i;

	i = 0;
	pt = 0;
	pt = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!pt)
		return (NULL);
	while (s1[i])
	{
		pt[i] = s1[i];
		i++;
	}
	pt[i] = '\0';
	return (pt);
}
