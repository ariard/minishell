/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_column.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 23:46:05 by ariard            #+#    #+#             */
/*   Updated: 2017/01/17 00:35:17 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_maxis(t_dlist **list_show)
{
	t_dlist	*tmp;
	int		max;

	tmp = *list_show;
	max = 0;
	while (tmp)
	{
		if ((int)ft_strlen(tmp->data) > max)
			max = ft_strlen(tmp->data);
		tmp = tmp->next;
	}
	return (max);
}

int			ft_lineis(int column, t_col *col)
{
	int		line;
	int		block;

	if (col->size == 0)
		return (0);
	block = column / col->max;
	if (block == 0)
		return (0);
	line = 0;
	while (block * line < col->size)
		line++;
	return (line);
}

int			ft_blockis(int column, t_col *col)
{
	int		line;
	int		block;

	if (col->size == 0)
		return (0);
	block = column / col->max;
	if (block == 0)
		return (0);
	line = 0;
	while (block * line < col->size)
		line++;
	if ((line - ((block * line) - col->size)) == 0)
		block--;
	return (block);
}

t_dlist		*ft_get_normal(t_dlist *elem, t_col *col)
{
	int		jump;
	int		bis;
	int		lencol;

	lencol = col->size / col->block;
	bis = col->block - (col->nb + 1);
	jump = bis * (lencol + 1);
	while (elem->next && jump)
	{
		elem = elem->next;
		jump--;
	}
	if (jump == 0)
		return (elem);
	return (NULL);
}

t_dlist		*ft_get_special(t_dlist *elem, t_col *col)
{
	int		jump;
	int		bis;
	int		lencol;

	lencol = col->size / col->block;
	bis = col->block - (col->nb + 1);
	jump = bis * lencol;
	while (elem->next && jump)
	{
		elem = elem->next;
		jump--;
	}
	if (jump == 0)
		return (elem);
	return (NULL);
}
