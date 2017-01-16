/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 22:13:19 by ariard            #+#    #+#             */
/*   Updated: 2017/01/16 22:48:45 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_entry		*ft_gen_entry(char *bin, char *path)
{
	t_entry			*entry;

	entry = ft_memalloc(sizeof(t_entry));
	entry->bin = ft_strdup(bin); 
	entry->path = ft_strdup(path);
	entry->perm = access(path, X_OK);
	return (entry);
}

static void			ft_clear_entry(void __unused *entry)
{
	return ;
}

static void			ft_read_path(t_cht *htb, char *exe, t_dlist **list_bin)
{
	DIR				*ds;
	struct dirent 	*lu;
	char			path[256];
	int				i;

	i = 0;
	ds = opendir(exe);
	while ((lu = readdir(ds)))
	{
		if (lu->d_name[0] != '.')
		{
			ft_bzero(path, 256);
			ft_strcpy(path, exe);
			ft_strncat(path, "/", 1);
			ft_strcat(path, lu->d_name);	
			ft_cht_insert(htb, ft_gen_entry(lu->d_name, path), 
					ft_strdup(lu->d_name), &ft_strcmp);
			ft_list_push_front(list_bin, ft_strdup(lu->d_name), 
					ft_strdup(lu->d_name));
		}
	}
	closedir(ds);
}

t_cht				*ft_gen_symtab(char **array, t_dlist **list_bin)
{
	char		*path;
	char		exe[128];
	char		*new;
	t_cht		*htb;
	int			i;	

	i = 0;
	htb = ft_memalloc(sizeof(t_cht));
	ft_cht_init(htb, 2441, &ft_hash_string, &ft_clear_entry);
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
		new = ft_strdup(exe);
		ft_read_path(htb, new, list_bin);
		path += ft_strlen(exe) + 1;
	}
	return (htb);
}
