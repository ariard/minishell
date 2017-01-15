/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:55:47 by ariard            #+#    #+#             */
/*   Updated: 2017/01/09 18:08:03 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

char			*ft_strtrim(char const *s)
{
	char		*new;
	char		*tmp;
	size_t		len;

	if (!s)
		return (NULL);
	new = 0;
	while ((*s == ' ' || *s == '\n' || *s == '\t') && *s)
		s++;
	len = ft_strlen(s) - 1;
	while ((s[len] == ' ' || s[len] == '\n' || s[len] == '\t') && *s)
		len--;
	len++;
	new = (char *)malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	tmp = new;
	ft_strncpy(new, s, len);
	new[len] = '\0';
	return (tmp);
}
