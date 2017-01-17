/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 21:07:29 by ariard            #+#    #+#             */
/*   Updated: 2017/01/18 00:22:07 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			ft_match(char *data, char *pattern)
{
	char		*tmp;
	int			pos;

	tmp = data;
	while (*(tmp + 1))
		tmp++;
	pos = ft_strlen(data);
	while (*tmp)
	{
		if (ft_strncmp(tmp, pattern, ft_strlen(pattern)) == 0)
				return (pos);
		tmp--;
		pos--;
	}
	return (0);
}

static char			*ft_match_history(int next, char *pattern,
		t_info *info)
{
	static t_dlist		*hist;
	static int			pos;

	if (!hist) 
		hist = info->history;
	if (next == 1 && hist)
		if (hist->next)
			hist = hist->next;
	while (hist)
	{
		if ((pos = ft_match(hist->data, pattern)) > 0)
			return (hist->data);
		if (hist->next)
			hist = hist->next;
		else
			break;
	}
	return (NULL);
}

static void		ft_show_hist(char *new, char *pattern, t_screen *new_screen)
{
	ft_delete_even_prompt(new_screen);
	ft_insert_str("(reverse-i-search)`", new_screen);
	if (ft_strlen(pattern) > 0)
		ft_insert_str(pattern, new_screen);
	ft_insert_str("': ", new_screen);
	ft_insert_str(new, new_screen);

}

void			ft_reverse_history(char *buffer, t_screen *screen, t_info *info)
{
	char		c;
	char		*new;
	char		*pattern;
	t_screen	*new_screen;
	
	pattern = ft_strnew(1024);
	new = ft_strdup(buffer);
	new_screen = ft_memalloc(sizeof(t_screen));
	ft_save_screen(new_screen, screen);
	ft_delete_even_prompt(new_screen);
	while (1)
	{
		c = '\0';
		read(0, &c, 1);
		if (ft_read_cursor(c) == 1)
			break;
		if (c == 13)
			break;
		if (c == 127)
		{
			ft_update_pattern(pattern);
			if (ft_strlen(pattern) > 0)
				new = ft_match_history(0, pattern, info);
		}
		if (c == 18)
		{
			new = ft_match_history(1, pattern, info);	
			ft_show_hist(new, pattern, new_screen);
		}
		if (ft_isprint(c) == 1)
		{
			ft_strncat(pattern, &c, 1);
			new = ft_match_history(0, pattern, info);
			ft_show_hist(new, pattern, new_screen);
		}
	}
	ft_delete_even_prompt(screen);
	ft_insert_str("ariard-1.0$> ", screen);
	ft_insert_str(new, screen);
	ft_goto_pos(screen->cursor, screen);
}
