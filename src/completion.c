/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 22:33:38 by ariard            #+#    #+#             */
/*   Updated: 2017/02/25 16:25:18 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_clean_list(t_dlist **list_files, t_dlist **list_show)
{
	ft_list_clear(list_files, &free);
	ft_list_clear(list_show, &free);
}	

void		ft_search_match(char *buffer, t_dlist **list_bin, 
		t_dlist **list_show, t_screen *screen)
{
	t_dlist 	*tmp;

	tmp = *list_bin;
	while (tmp)
	{
		if (ft_strncmp(buffer, tmp->key, screen->match) == 0)
			ft_list_push_back(list_show, ft_strdup(tmp->key), 
					ft_strdup(tmp->key));
		tmp = tmp->next;
	}
}

void			ft_complete_bin(char *buffer, t_dlist **list_bin, t_screen *screen)
{
	t_dlist		**list_show;
	t_dlist		*tmp;
	int			size;


	list_show = ft_memalloc(sizeof(t_dlist));
	screen->match = screen->cursor;
	ft_search_match(buffer, list_bin, list_show, screen);
	tmp = *list_show;
	size = ft_list_size(list_show);
	if (size == 0)
		size = ft_list_size(list_bin);
	if (ft_ask_user(size, buffer, screen) == -1)
		return (ft_list_clear(list_show, &free));	
	if (size == ft_list_size(list_bin))
		ft_print_column(buffer, list_bin, screen);
	else if (size > 1)
		ft_print_column(buffer, list_show, screen);
	else if (size == 1)
		ft_swap_buffer(buffer, tmp->key, screen);
	return (ft_list_clear(list_show, &free));
}

int			ft_isuncompletepath(char *str)
{
	char	tmp[256];
	char	*tmp2;

	if (str[0] != '/')
		return (-1);
	str++;
	ft_bzero(tmp, 256);
	ft_strcat(tmp, "/");
	while (*str)
	{
		tmp2 = str;
		while (*str && *str != '/')
			str++;
		ft_strncat(tmp, tmp2, ft_strlenchr(tmp2, '/'));
		ft_strcat(tmp, "/");
		if (ft_isdir(tmp) == 0)
			return (1);
		str++;
	}
	return (0);
}	
