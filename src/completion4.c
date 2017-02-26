/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 16:51:45 by ariard            #+#    #+#             */
/*   Updated: 2017/02/26 17:34:13 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_complete_question(char *question, int size)
{
	char	*str_size;

	ft_bzero(question, 256);
	ft_strcpy(question, "Display all ");
	str_size = ft_itoa(size);
	ft_strcat(question, str_size);
	ft_strdel(&str_size);
	ft_strcat(question, " possibilites? (y or n)");
	return (0);
}

void		ft_complete_arg2(t_dlist **list_files, char *files,
			t_screen *screen, char *buffer)
{
	t_dlist **list_show;
	int		size;
	char	*tmp;

	list_show = ft_memalloc(sizeof(t_dlist));
	screen->match = screen->cursor - screen->match;
	ft_search_match(files, list_files, list_show, screen);
	size = ft_list_size(list_show);
	if (size == 0 && files[0] == 0)
		size = ft_list_size(list_files);
	if (ft_ask_user(size, buffer, screen) == -1)
		return (ft_clean_list(list_files, list_show));
	if (size == 1)
	{
		tmp = ft_set_new_arg(buffer, list_show);
		ft_swap_buffer(buffer, tmp, screen);
		ft_strdel(&tmp);
	}
	else if (size == ft_list_size(list_files))
		ft_print_column(buffer, list_files, screen);
	else if (size > 1)
		ft_print_column(buffer, list_show, screen);
	return (ft_clean_list(list_files, list_show));
}

void		ft_complete_path2(t_dlist **list_show, t_screen *screen,
			char *buffer, char *valid_path)
{
	char	*match;
	int		size;

	size = ft_list_size(list_show);
	if (size > 1)
		ft_print_column(buffer, list_show, screen);
	else if (size == 1)
	{
		match = ft_set_new_path(buffer, valid_path, list_show);
		ft_swap_buffer(buffer, match, screen);
		ft_strdel(&match);
	}
	ft_strdel(&valid_path);
}
