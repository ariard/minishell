/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 20:39:19 by ariard            #+#    #+#             */
/*   Updated: 2017/01/19 17:06:06 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_read_entry(t_cht *htb)
{
	int i;

	i = 0;
	while (i < 2300)
	{
		if (htb->head)	
			if (htb->head[i])
				if (htb->head[i]->key)
				{
					ft_putstr("entree: ");
					ft_putstr(htb->head[i]->key);
					ft_putchar(10);
				}
		i++;
	}
}

void			ft_read_list(t_dlist **list)
{
	t_dlist		*tmp;
	t_token		*token;
	int			i;

	if (!list || !*list)
		return ;
	tmp = *list;
	i = 0;
	while (tmp)
	{
		if (tmp->data)
		{
			token = tmp->data;
			if (token)
			{
				if (token->id)
				{
					ft_putstr(token->id);
					ft_putstr(" : ");
				}
				if (token->name)
					ft_putstr(token->name);
				ft_putchar(10);
			}
		}
		tmp = tmp->next;
	}
}

void			ft_read_env(char **str)
{
	while (*str)
	{
		ft_putstr(*str++);
		ft_putchar(10);
	}
}

void			ft_read_list2(t_dlist *begin_list)
{
	t_dlist		*tmp;

	tmp = begin_list;
	while (tmp)
	{
		ft_putstr(tmp->data);
		ft_putchar(10);
		tmp = tmp->next;
	}
}

void			ft_read_list3(t_dlist *begin_list)
{
	t_dlist		*tmp;

	tmp = ft_list_last(&begin_list);
	while (tmp)
	{
		ft_putstr(tmp->data);
		ft_putchar(10);
		tmp = tmp->previous;
	}
}
