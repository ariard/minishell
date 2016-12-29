/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:25:45 by ariard            #+#    #+#             */
/*   Updated: 2016/11/25 19:42:50 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	if ((mem = (void *)malloc(size)) && size)
	{
		ft_bzero(mem, size);
		return (mem);
	}
	return (NULL);
}
