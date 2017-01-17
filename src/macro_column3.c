/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 22:33:38 by ariard            #+#    #+#             */
/*   Updated: 2017/01/17 19:59:45 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_display(t_col *col, t_dlist *elem)
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

void		ft_display_columns(t_dlist **list_show, int column)
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

char		*ft_set_new_path(char *buffer, char *path, t_dlist **list)
{
	t_dlist	*tmp;
	char	*new;
	int		spaces;

	tmp = *list;
	new = ft_strnew(256);
	ft_strncpy(new, buffer, ft_strlenchr(buffer, 32));
	spaces = ft_count_char(buffer, &ft_isspace);
	while (spaces--)
		ft_strcat(new, " ");
	ft_strcat(new, path);
	ft_strcat(new, tmp->key);
	return (new);
}
