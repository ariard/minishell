/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strduptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:37:12 by ariard            #+#    #+#             */
/*   Updated: 2017/01/06 14:02:18 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

char		*ft_strduptr(char *str, int (*is)(int c))
{
	char	*new;
	char	*tmp;

	new = ft_memalloc(sizeof(char *) * ft_strlen(str) + 1);
	tmp = new;
	while (*str && (is)((int)*str) == 0)
		*new++ = *str++;
	*new = 0;
	return (tmp);
}
