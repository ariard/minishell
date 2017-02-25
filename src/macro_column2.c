/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_column2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 00:09:45 by ariard            #+#    #+#             */
/*   Updated: 2017/02/25 14:42:35 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_space(char *buf, int max, char *s)
{
	int		to_space;

	to_space = max - (int)ft_strlen(s);
	while (to_space--)
		ft_strcat(buf, " ");
}

int			ft_isparent(char *str)
{
	if ((str[0] != '.' || str[1] != '.') &&
			(str[0] != '.' || str[1] != 0))
		return (0);
	return (1);
}

void		ft_print_column(char *buffer, t_dlist **list, t_screen *screen)
{
	char	*prompt;
	
	prompt = "ariard-1.0$> ";
	ft_putchar(10);
	ft_display_columns(list, ft_iscol());
	ft_insert_str(prompt, screen);
	ft_insert_str(buffer, screen);
	ft_goto_pos(screen->cursor, screen);
}

char		*ft_set_new_arg(char *buffer, t_dlist **list)
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
	ft_strcat(new, tmp->key);
	return (new);
}

int		ft_isdir(char *str)
{
	DIR *ds;

	ds = opendir(str);
	if (ds)
	{
		closedir(ds);
		return (1);
	}
	return (0);
}
