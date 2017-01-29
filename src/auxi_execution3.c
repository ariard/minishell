/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi_execution3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 15:33:31 by ariard            #+#    #+#             */
/*   Updated: 2017/01/29 21:02:59 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_entry		*ft_gen_entry(char *bin, char *path)
{
	t_entry		*entry;
	
	entry = ft_memalloc(sizeof(t_entry));
	entry->path = ft_strjoin(ft_strcat(path, "/"), bin);
	entry->perm = access(entry->path, X_OK);
	return (entry);
}

int			ft_search_bin(char *dir, char *bin)
{
	DIR				*ds;
	struct dirent	*lu;

	if (!dir || !bin)
		return (0);
	ds = opendir(dir);
	if (!ds)
		return (0);
	while ((lu = readdir(ds)))
	{
		if (ft_strcmp(bin, lu->d_name) == 0)
			return (1);
	}
	return (0);
}
		
t_entry			*ft_add_bin(char *bin, t_info *info)
{
	char	*path;
	char	*dir;
	t_entry *entry;

	path = ft_grep_envdata(info->env, "PATH");
	if (!path)
		return (NULL);
	while (*path)
	{
		dir = ft_strnew(256);
		ft_strchrcpy(dir, path, ':');
		if (ft_search_bin(dir, bin))
		{
			entry = ft_gen_entry(bin, dir);
			ft_cht_insert(info->sym_tab, entry, entry->path, &ft_strcmp);
			ft_strdel(&dir);
			return (entry);
		}
		else
			path += ft_strlen(dir) + 1;
		ft_strdel(&dir);
	}
	return (NULL);
}

int			ft_full_path(char *full_path)
{
	if (!(ft_strchr(full_path, '/')))
		return (0);
	if (access(full_path, F_OK) == -1)
		return (0);
	return (1);
}	
