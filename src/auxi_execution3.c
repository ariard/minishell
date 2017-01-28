/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi_execution3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 15:33:31 by ariard            #+#    #+#             */
/*   Updated: 2017/01/28 16:55:18 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_entry		*ft_gen_entry(char *bin, char *path, int n)
{
	t_entry		*entry;
	
	entry = ft_memalloc(sizeof(t_entry));
	if (n == 0)
		entry->path = ft_strjoin(ft_strcat(path, "/"), bin);
	if (n == 1)
		entry->path = ft_strdup(bin);
	entry->perm = access(path, X_OK);
	return (entry);
}

int			ft_search_bin(char *dir, char *bin)
{
	DIR				*ds;
	struct dirent	*lu;
	char			tmp[1024];

	if (!dir || !bin)
		return (0);
	ds = opendir(dir);
	if (!ds)
		return (0);
	while ((lu = readdir(ds)))
	{
		ft_bzero(tmp, 1024);
		ft_strcpy(tmp, dir);
		ft_strcat(tmp, "/");
		ft_strcat(tmp, lu->d_name);
		if (ft_strcmp(bin, lu->d_name) == 0)
			return (1);
		if (ft_strcmp(bin, tmp) == 0)
			return (2);
	}
	return (0);
}
		
t_entry			*ft_add_bin(char *bin, t_info *info)
{
	char	*path;
	char	*dir;
	int		ret;
	t_entry *entry;

	entry = NULL;
	path = ft_grep_envdata(info->env, "PATH");
	while (*path)
	{
		dir = ft_strnew(256);
		ft_strchrcpy(dir, path, ':');
		if ((ret = ft_search_bin(dir, bin)))
		{
			if (ret == 2)
				entry = ft_gen_entry(bin, dir, 1);
			else if (ret == 1)
				entry = ft_gen_entry(bin, dir, 0);
			ft_cht_insert(info->sym_tab, entry, entry->path, &ft_strcmp);
			return (entry);
		}
		else
		{
			path += ft_strlen(dir) + 1;
			ft_strdel(&dir);
		}
	}
	return (NULL);
}
