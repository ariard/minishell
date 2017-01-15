/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 15:32:59 by ariard            #+#    #+#             */
/*   Updated: 2016/12/29 19:39:16 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

t_dlist	*ft_list_push_params(int argc, char **argv, t_dlist *(*create)(void *))
{
	t_dlist		**begin_list;

	begin_list = NULL;
	while (argc--)
	{
		ft_list_push_front(begin_list, argv, create);
		argv++;
	}
	return (*begin_list);
}
