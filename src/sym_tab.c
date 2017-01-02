/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 22:13:19 by ariard            #+#    #+#             */
/*   Updated: 2017/01/03 00:44:40 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		**ft_array_strdup(char **env)
{
	int			size;
	char		**tmp;
	char		**new;

	size = 0;
	tmp = env;
	while (*tmp++)
		size++;
	new = ft_memalloc(sizeof(char *) * (size + 1));
	tmp = new;
	while (*env)
		*new++ = ft_strdup(*env++);
	*new = 0;
	return (tmp);
}

static void		ft_read_path(char *exe)
{
	DIR				*ds;
	struct dirent 	*lu;

	ds = opendir(exe);
	while ((lu = readdir(ds)))
	{
		if (lu->d_name[0] != '.')
		{
			ft_putstr(lu->d_name);
			ft_putchar(10);
		}
	}
	closedir(ds);
}

t_cht			*ft_gen_symtab(char **env)
{
	char		**array;
	char		*path;
	char		exe[128];

	array =	ft_array_strdup(env);
	while (ft_strncmp(*array, "PATH", 4) != 0)
		array++;
	path = *array;
	while (*path != '=')
		path++;
	path++;
	while (*path)
	{
		ft_bzero(exe, 128);
		ft_strchrcpy(exe, path, ':');
		ft_read_path(exe);
		path += ft_strlen(exe) + 1;
	}
	return (NULL);
}
