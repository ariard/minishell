/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 20:04:50 by ariard            #+#    #+#             */
/*   Updated: 2017/02/27 20:56:10 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "dlist.h"

void		ft_bubble_cmpsort(t_dlist **begin_list, int (*cmp)(const void *key1,
			const void *key2));

void		ft_insert_keysort(t_dlist **begin_list);

void		ft_insert_cmpsort(t_dlist **begin_list,
		int (*cmp)(const void *key1, const void *key2));

int			ft_stralphcmp(const void *s1, const void *s2);

#endif
