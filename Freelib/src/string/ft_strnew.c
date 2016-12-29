/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:50:26 by ariard            #+#    #+#             */
/*   Updated: 2016/12/06 22:21:36 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	new = 0;
	new = (char *)malloc(sizeof(char) * (size) + 1);
	if (!(new))
		return (NULL);
	ft_bzero(new, size + 1);
	return (new);
}
