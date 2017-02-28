/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 17:51:25 by ariard            #+#    #+#             */
/*   Updated: 2017/01/15 16:51:02 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLIST_H
# define DLIST_H

typedef struct		s_dlist
{
	struct s_dlist	*next;
	struct s_dlist	*previous;
	void			*data;
	void			*key;
}					t_dlist;

t_dlist				*ft_create_elem(void *data, void *key);

void				ft_list_push_back(t_dlist **begin_list, void *data,
		void *key);

void				ft_list_push_front(t_dlist **begin_list, void *data,
		void *key);

int					ft_list_size(t_dlist **begin_list);

t_dlist				*ft_list_last(t_dlist **begin_list);

t_dlist				*ft_list_push_params(int argc, char **argv,
		t_dlist *(*create)(void *));

void				ft_list_clear(t_dlist **begin_list,
		void (*destroy)(void *));

void				ft_list_reverse(t_dlist **begin_list);

void				ft_list_foreach(t_dlist **begin_list, void (*f)(void *));

t_dlist				*ft_list_find(t_dlist **begin_list, void *data_ref,
	int (*cmp)());

void				ft_list_cycle(t_dlist **begin_list);

void				ft_list_rem_front(t_dlist **begin_list);

void				ft_list_swap(t_dlist **begin_list, t_dlist *node1,
		t_dlist *node2);

t_dlist				*ft_list_rem(t_dlist **begin_list, t_dlist *node);

void				ft_list_ins(t_dlist *node1, t_dlist *node2);

void				ft_list_init(t_dlist **begin_list,
		void (*destroy)(void *data));

t_dlist				*ft_list_next(t_dlist *current, int next);

#endif
