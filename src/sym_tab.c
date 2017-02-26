/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 22:13:19 by ariard            #+#    #+#             */
/*   Updated: 2017/02/26 19:55:15 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			ft_clear_entry(void __unused *entry)
{
	return ;
}

static void			ft_read_path(char *exe, t_dlist **list_bin)
{
	DIR				*ds;
	struct dirent 	*lu;
	int				i;

	i = 0;
	if(!(ds = opendir(exe)))
		return ;
	while ((lu = readdir(ds)))
	{
			if (lu->d_name[0] != '.')
				ft_list_push_front(list_bin, ft_strdup(lu->d_name), 
					ft_strdup(lu->d_name));
	}
	closedir(ds);
}

t_cht				*ft_gen_symtab(t_info *info)
{
	t_cht		*htb;
	char		*new;
	char		*path;

	htb = ft_memalloc(sizeof(t_cht));
	ft_cht_init(htb, 2441, &ft_hash_string, &ft_clear_entry);
	path = ft_grep_envdata(info->env, "PATH");
	if (!path)
		return (htb);
	while (*path)
	{
		new = ft_strnew(256);
		ft_strchrcpy(new, path, ':');
		ft_read_path(new, info->list_bin);
		path += ft_strlen(new) + 1;
		ft_strdel(&new);
	}	
	return (htb);
}
