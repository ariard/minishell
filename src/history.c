/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 16:40:57 by ariard            #+#    #+#             */
/*   Updated: 2017/02/21 10:32:47 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_gen_history(t_info *info)
{
	int			fd;
	int			ret;
	char		*line;

	fd = open("/Users/ariard/.ariard_history", O_RDONLY | O_CREAT, 0644);
	if (fd == -1)
		return ;
	line = 0;
	ret = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
//		ft_list_push_front(&info->history, ft_strdup(line), NULL);
		ft_strdel(&line);
		ret++;
	}
//	ft_list_push_front(&info->history, ft_strdup(""), NULL);
	info->sizehist = ret;
	sleep(5);
	ft_putstr("first sleep");
	close(fd);
	sleep(10);
}

static void		ft_save_current_buff(char *buffer, t_info *info)
{
	t_dlist		*tmp;

	tmp = info->history;
	ft_memdel(&tmp->data);
	ft_list_rem_front(&info->history);
	ft_list_push_front(&info->history, ft_strdup(buffer), NULL);
}

void			ft_read_history(int n, char *buffer, t_screen *screen, t_info *info)
{
	static t_dlist	*hist;
	static int		index;

	if (!index)
		index = 0;
	if (index == 0 && n == 0)
		return ;
	if (info->history)
		if (index == 0 && ft_strcmp(buffer, (info->history)->data) != 0) 
		{
			ft_save_current_buff(buffer, info);
			hist = info->history;
		}

	if (!hist)
		hist = info->history;
	if (n == 0 && hist->previous)
	{
		hist = hist->previous;
		index--;
	}
	else if (n == 1 && hist->next)
	{
		hist = hist->next;
		index++;
	}
	if (hist)
		if (hist->data)
			ft_show_history(hist->data, buffer, screen);
}

void		ft_show_history(char *str, char *buffer, t_screen *screen)
{
	if (ft_strcmp(str, buffer) == 0)
		return ;
	ft_delete_all(screen);
	ft_insert_str(str, screen);
	screen->cursor = ft_strlen(str);
	screen->vertical = ((screen->cursor + screen->left) / screen->col) + 1;
	ft_bzero(buffer, 1024);
	ft_strcpy(buffer, str);
}

void		ft_add_history(char *buffer, t_info *info)
{
	t_dlist	*elem;

	elem = ft_create_elem(ft_strdup(buffer), NULL);
	ft_list_ins(info->history, elem);
}			
