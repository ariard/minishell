/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 21:07:29 by ariard            #+#    #+#             */
/*   Updated: 2017/02/21 10:38:33 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			ft_match(char *data, char *pattern)
{
	char		*tmp;

	tmp = data;
	while (*(tmp + 1))
		tmp++;
	while (*tmp)
	{
		if (ft_strncmp(tmp, pattern, ft_strlen(pattern)) == 0)
			return (1);
		tmp--;
	}
	return (0);
}

static char			*ft_match_history(int flag, char *new, char *pattern,
		t_info *info)
{
	static t_dlist		*hist;

	if (flag == 2)
	{
		hist = info->history;
		return (NULL);
	}
	if (flag == 1 && hist) 
		if (hist->next)
			hist = hist->next;
	while (hist)
	{
		if ((ft_match(hist->data, pattern)) > 0)
			return (ft_strdup(hist->data));
		if (hist->next)
			hist = hist->next;
		else
			break;
	}
	return (new);
}

static void		ft_show_hist(char *new, char *pattern, t_screen *new_screen)
{
	(void)new_screen;
	ft_putstr("(reverse-i-search)'");
	ft_putstr(pattern);
	ft_putstr("': ");
	ft_putstr(new);
}

void			ft_reverse_history(char *buffer, t_screen *screen, t_info *info)
{
	char		c;
	char		*new;
	char		*pattern;
	t_screen	*new_screen;
	
	pattern = ft_strnew(1024);
	new = ft_strdup(buffer);
	if (!new)
		new = 0;
	new_screen = ft_memalloc(sizeof(t_screen));
	ft_save_screen(new_screen, screen);
	ft_delete_even_prompt(new, pattern, new_screen);
	ft_show_hist(new, pattern, new_screen);
	ft_match_history(2, NULL, NULL, info);
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
				new = ft_match_history(0, new, pattern, info);
			ft_delete_even_prompt(new, pattern, new_screen);
			ft_show_hist(new, pattern, new_screen);
		}
		if (c == 18 && ft_strlen(pattern) > 0)
		{
			ft_delete_even_prompt(new, pattern, new_screen);
			new = ft_match_history(1, new, pattern, info);
			ft_show_hist(new, pattern, new_screen);
		}
		if (ft_isprint(c) == 1)
		{
			ft_delete_even_prompt(new, pattern, new_screen);
			ft_strncat(pattern, &c, 1);
			new = ft_match_history(0, new, pattern, info);
			ft_show_hist(new, pattern, new_screen);
		}
	}
	ft_delete_even_prompt(buffer, pattern, new_screen);
	ft_putstr("ariard-1.0$> ");
	ft_putstr(new);
	ft_bzero(buffer, 1024);
	ft_strcpy(buffer, new);
	screen->cursor = ft_strlen(buffer);
	screen->col = ft_iscol();
	screen->vertical = ((ft_strlen(buffer) + screen->left) / screen->col) + 1;
}
