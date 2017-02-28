/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpyptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 12:11:15 by ariard            #+#    #+#             */
/*   Updated: 2017/02/14 12:17:32 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

char		*ft_strcpyptr(char *dst, char *src, int (*is)(int c))
{
	char	*tmp;

	tmp = dst;
	while (*src && *dst && (is)((int)*src) == 0)
		*dst++ = *src++;
	*dst = 0;
	return (tmp);
}
