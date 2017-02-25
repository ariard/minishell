/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:10:56 by ariard            #+#    #+#             */
/*   Updated: 2017/02/25 16:21:08 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_read_dir(char *dir, t_dlist **list_files)
{
	DIR *ds;
	struct dirent *lu;

	ds = opendir(dir);
	if (ds)
	{
		while ((lu = readdir(ds)))
			if (ft_isparent(lu->d_name) == 0)
				ft_list_push_back(list_files, ft_strdup(lu->d_name),
					ft_strdup(lu->d_name));
		closedir(ds);
		if (*list_files)
		{
			ft_insert_cmpsort(list_files, &ft_stralphcmp);
			ft_list_reverse(list_files);
		}
		return (0);
	}
	return (1);
}

int			ft_ask_user(int	size, char *buffer, t_screen *screen)
{
	char	question[256];
	char	*prompt;
	char	*str_size;
	int		c;

	c = '\0';
	if (size >= 100)
	{
		prompt = "ariard-1.0$> ";
		ft_bzero(question, 256);
		ft_strcpy(question, "Display all ");
		str_size = ft_itoa(size);
		ft_strcat(question, str_size);
		ft_strdel(&str_size);
		ft_strcat(question, " possibilities? (y or n)");
		ft_insert(10);
		ft_insert_str(question, screen);
		read(0, &c, 1);
		if (c == 'y')
			return (1);
		else
		{
			ft_insert(10);
			ft_insert_str(prompt, screen);
			ft_insert_str(buffer, screen);
			return (-1);
		}
	}
	return (1);
}

void		ft_complete_arg(char *buffer, char *files, t_screen *screen)
{
	t_dlist	**list_files;
	t_dlist	**list_show;
	int		size;
	char	*dir;
	char	*tmp;

	list_files = ft_memalloc(sizeof(t_dlist));
	list_show = ft_memalloc(sizeof(t_dlist));
	dir = files;
	if (files[0] == 0 || ft_isdir(files) == 0) 
		dir = ".";
	ft_read_dir(dir, list_files);
	if (ft_isdir(files) == 1)
	{
		size = ft_list_size(list_files);
		if (ft_ask_user(size, buffer, screen) == -1)
			return (ft_clean_list(list_files, list_show));
		ft_print_column(buffer, list_files, screen);
	}
	else
	{
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
	}
	return (ft_clean_list(list_files, list_show));
}

void		ft_complete_switch(char *buffer, t_dlist **list_bin,
		t_screen *screen)
{
	char	*tmp;
	int		inword;
	
	inword = 0;
	screen->match = 0;
	tmp = buffer;
	while (*tmp)
	{
		if (ft_isspace(*tmp) == 0)
			inword = 1;
		if (ft_isspace(*tmp) == 1 && inword == 1)
		{
			while (*tmp && ft_isspace(*tmp) == 1)
			{
				tmp++;
				screen->match++;
			}
			if (ft_isuncompletepath(tmp) == 1)
				ft_complete_path(buffer, tmp, screen);	
			else
				ft_complete_arg(buffer, tmp, screen);
			return ;
		}	
		tmp++;
		screen->match++;
	}
	ft_complete_bin(buffer, list_bin, screen);
}
