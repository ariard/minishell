/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:54:24 by ariard            #+#    #+#             */
/*   Updated: 2017/01/05 17:56:39 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

t_dlist		*ft_list_next(t_dlist *current, int next)
{
	while (current && next--)
		current = current->next;
	return (current);
}
