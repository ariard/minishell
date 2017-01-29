/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:27:35 by ariard            #+#    #+#             */
/*   Updated: 2017/01/28 22:28:37 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_construct_path(char **new_tab_dir)
{
	char	*path;

	if (!new_tab_dir)
		return (NULL);
	path = ft_strnew(256);
	ft_strcat(path, "/");
	while (*new_tab_dir)
	{
		if (ft_strcmp(".", *new_tab_dir) != 0)
		{
			if (*(new_tab_dir + 1))
			{
				if (ft_strcmp(*(new_tab_dir + 1), "..") != 0)
				{
					ft_strcat(path, *new_tab_dir);
					ft_strcat(path, "/");
				}
			}
			else
				ft_strcat(path, *new_tab_dir);
		}
		if (ft_check_dir(path) == -1)
			return (NULL);
		new_tab_dir++;
	}
	return (path);
}

int			ft_process_cd(char *curpath, char *option, t_info *info)
{
	char	**new_tab_dir;
	char	*path;
	char	**tmp;

	(void)option;
	if (*curpath == '/')	
		curpath++;
	new_tab_dir = ft_strsplit(curpath, '/'); 
	if ((path = ft_construct_path(new_tab_dir)) == NULL)
		return (1);
	if (chdir(path) == 0)
	{
		tmp = ft_grep_env(info->env, "OLDPWD");
		free(*tmp);
		*tmp = ft_strjoin("OLDPWD=", ft_grep_envdata(info->env, "PWD"));
		tmp = ft_grep_env(info->env, "PWD");
		free(*tmp);
		*tmp = ft_strjoin("PWD=", path);
		free(path);
	}
	return (1);
}

char		*ft_read_cdpath(char *arg, char **env)
{
	char	**new_tab;
	char	*path;
	char	*data;

	data = ft_grep_envdata(env, "CDPATH");
	new_tab = ft_strsplit(data, ';');
	if (!new_tab)
		return (NULL);
	path = ft_strnew(256);
	while (*new_tab)
	{	
		ft_strcpy(path, *new_tab);
		ft_strcat(path, "/");
	   	ft_strcat(path, arg);
		ft_bzero(path, 256);
		new_tab++;
	}
	ft_strcat(path, "./");
	ft_strcat(path, arg);
	if (ft_check_dir(path) == 1)
		return (path);
	free(path);
	return (NULL);
}
		
int			ft_cd(char **arg, t_info *info)
{
	char	*path;

	if (!arg)
		return (1);
	arg++;
	if (ft_grep_envdata(info->env, "HOME") == NULL && *arg == NULL)
		return (ft_home_error());
	if (ft_grep_envdata(info->env, "HOME") != NULL && *arg == NULL)
		return (ft_process_cd(ft_strdup(ft_grep_envdata(info->env, "HOME")),
			"HOME", info));
	if (ft_strcmp(*arg, "-") == 0)
		return (ft_process_cd(ft_grep_envdata(info->env, "OLDPWD"),
			ft_builtin_option(arg, "cd"), info));
	if (*arg)
	{	
		if (ft_strncmp(*arg, "/", 1) == 0)
			return (ft_process_cd(*arg, ft_builtin_option(arg, "cd"), info));
		if (ft_strncmp(*arg, ".", 1) != 0 || ft_strncmp(*arg, "..", 2) != 0)
			if ((path = ft_read_cdpath(*arg, info->env)) != NULL)
				return (ft_process_cd(path, ft_builtin_option(arg, "cd"),
					info));
		path = ft_strnew(256);	
		ft_strcpy(path, ft_grep_envdata(info->env, "PWD"));
		ft_strcat(path, "/");
		ft_process_cd(ft_strcat(path, *arg), ft_builtin_option(arg, "cd"),
			info);
	}
	return (1);
}
