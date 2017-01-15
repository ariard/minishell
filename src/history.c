/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 16:40:57 by ariard            #+#    #+#             */
/*   Updated: 2017/01/15 18:41:26 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_gen_history(t_info *info)
{
	int			fd;
	int			ret;
	char		*line;
	t_dlist		**list_history;

	fd = open("/Users/ariard/.ariard_history", O_RDONLY | O_CREAT, 0644);
	line = 0;
	list_history = ft_memalloc(sizeof(t_dlist));
	*list_history = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
		ft_list_push_front(list_history, line, line);
	info->history = *list_history;
}

void			ft_read_history(int n, char *buffer, t_screen *screen, t_info *info)
{
	static t_dlist	*hist;

	if (!hist)
		hist = info->history;
	if (n == 0)
	{
		ft_show_history(hist->data, buffer, screen);
		if (hist->previous)
			hist = hist->previous;
	}
	else if (n == 1)
	{
		ft_show_history(hist->data, buffer, screen);
		if (hist->next)
			hist = hist->next;
	}
}

void		ft_show_history(char *str, char *buffer, t_screen *screen)
{
	ft_delete_all(screen);
	ft_insert_str(str, screen);
	screen->cursor = ft_strlen(str);
	screen->vertical = ((screen->cursor + screen->left) / screen->col) + 1;
	ft_bzero(buffer, 1024);
	ft_strcpy(buffer, str);
}
