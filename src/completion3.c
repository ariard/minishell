/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:20:31 by ariard            #+#    #+#             */
/*   Updated: 2017/01/17 20:40:20 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*ft_get_valid_path(char *path)
{
	char	tmp[256];
	char	*tmp2;
	char	*tmp3;

	ft_bzero(tmp, 256);
	ft_strcat(tmp, "/");
	path++;
	while (*path)
	{
		tmp2 = path;
		tmp3 = ft_strdup(tmp);
		while (*path && *path != '/')
			path++;
		ft_strncat(tmp, tmp2, ft_strlenchr(tmp2, '/'));
		ft_strcat(tmp, "/");
		if (ft_isdir(tmp) == 0)
			return (tmp3);
		path++;
		ft_strdel(&tmp3);
	}
	return (NULL);
}

static char		*ft_get_match(char *path)
{
	char	tmp[256];
	char	*tmp2;
	char	*tmp3;

	ft_bzero(tmp, 256);
	ft_strcat(tmp, "/");
	path++;
	while (*path)
	{
		tmp2 = path;
		tmp3 = tmp;
		while (*path && *path != '/')
			path++;
		ft_strncat(tmp, tmp2, ft_strlenchr(tmp2, '/'));
		ft_strcat(tmp, "/");
		if (ft_isdir(tmp) == 0)
			return (tmp2);
		path++;
	}
	return (NULL);
}

void			ft_complete_path(char *buffer, char *path, t_screen *screen)
{
	char	*valid_path;
	char	*match;
	int		size;
	t_dlist	**list_path;
	t_dlist	**list_show;

	list_path = ft_memalloc(sizeof(t_dlist));
	list_show = ft_memalloc(sizeof(t_dlist));
	valid_path = ft_get_valid_path(path);
	match = ft_get_match(path);
	screen->match = screen->cursor - screen->match - ft_strlen(valid_path);
	ft_read_dir(valid_path, list_path);
	ft_search_match(match, list_path, list_show, screen);
	size = ft_list_size(list_show);
	if (ft_ask_user(size, buffer, screen) == -1)
		return ;
	if (size > 1)
		ft_print_column(buffer, list_show, screen);
	else if (size == 1)
		ft_swap_buffer(buffer, ft_set_new_path(buffer, valid_path, list_show),
			screen);
}
