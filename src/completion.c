/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 22:33:38 by ariard            #+#    #+#             */
/*   Updated: 2017/01/17 00:34:29 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


static void		ft_search_match(char *buffer, t_dlist **list_bin, 
		t_dlist **list_show)
{
	t_dlist 	*tmp;

	tmp = *list_bin;
	while (tmp)
	{
		if (ft_strncmp(buffer, tmp->key, ft_strlen(buffer)) == 0)
			ft_list_push_back(list_show, ft_strdup(tmp->key), 
					ft_strdup(tmp->key));
		tmp = tmp->next;
	}
}

static void		ft_display(t_col *col, t_dlist *elem)
{
	char		buf[256];
	t_dlist		*tmp;
	
	ft_bzero(buf, 256);
	if (col->size == col->block * col->curse)
		tmp = ft_get_special(elem, col);
	else
		tmp = ft_get_normal(elem, col);
	if (tmp)
	{
		ft_strcpy(buf, tmp->data);
		ft_space(buf, col->max, tmp->data);
		if (col->nb == 0 || !(tmp->next))
			ft_strcat(buf, "\n");
		ft_putstr(buf);
	}
	else if (col->size != 1)
	{
		col->nb = 0;
		ft_putchar(10);
	}
}

static void		ft_display_columns(t_dlist **list_show, int column)
{
	t_dlist		*tmp;
	t_col		*col;

	tmp = *list_show;
	col = ft_memalloc(sizeof(t_col));
	if ((col->max = ft_maxis(list_show) + 1) == 1)
		return ;
	col->size = ft_list_size(list_show);
	col->line = ft_lineis(column, col);
	col->block = ft_blockis(column, col);
	col->curse = col->line;
	while (tmp && col->block && col->line)
	{
		col->nb = col->block;
		while (col->nb-- && tmp)
			ft_display(col, tmp);
		col->line--;
		tmp = tmp->next;
	}
}
	
void			ft_complete(char *buffer, t_dlist **list_bin)
{
	t_dlist		**list_show;

	list_show = ft_memalloc(sizeof(t_dlist));
	ft_search_match(buffer, list_bin, list_show);
	ft_putchar(10);
	ft_display_columns(list_show, ft_iscol());		
	return ;
}	
