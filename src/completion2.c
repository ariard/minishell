/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:10:56 by ariard            #+#    #+#             */
/*   Updated: 2017/02/26 18:16:37 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_read_dir(char *dir, t_dlist **list_files)
{
	DIR				*ds;
	struct dirent	*lu;

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

int			ft_ask_user(int size, char *buffer, t_screen *screen)
{
	char	question[256];
	char	*prompt;
	int		c;

	c = '\0';
	if (size >= 100)
	{
		prompt = "ariard-1.0$> ";
		ft_complete_question(question, size);
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
	int		size;
	char	*dir;

	list_files = ft_memalloc(sizeof(t_dlist));
	dir = files;
	if (files[0] == 0 || ft_isdir(files) == 0)
		dir = ".";
	ft_read_dir(dir, list_files);
	if (ft_isdir(files) == 1)
	{
		size = ft_list_size(list_files);
		if (ft_ask_user(size, buffer, screen) == -1)
			return (ft_clean_list(list_files, NULL));
		ft_print_column(buffer, list_files, screen);
	}
	else
		ft_complete_arg2(list_files, files, screen, buffer);
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
			while (*tmp && ft_isspace(*tmp) == 1 && *tmp++)
				screen->match++;
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
