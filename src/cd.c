/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:27:35 by ariard            #+#    #+#             */
/*   Updated: 2017/01/09 18:26:44 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_construct_path(char **tab_dir)
{
	char	*path;

	if (!tab_dir)
		return (NULL);
	path = ft_strnew(256);
	ft_strcat(path, "/");
	while (*tab_dir)
	{
		if (ft_strcmp(".", *tab_dir) != 0)
		{
			if (*(tab_dir + 1))
			{
				if (ft_strcmp(*(tab_dir + 1), "..") != 0)
				{
					ft_strcat(path, *tab_dir);
					ft_strcat(path, "/");
				}
			}
			else
			{
				ft_strcat(path, *tab_dir);
				ft_strcat(path, "/");
			}
		}
		if (ft_check_dir(path) == -1)
			return (NULL);
		tab_dir++;
	}
	return (path);
}

int			ft_process_cd(char *curpath, char *option, char **env)
{
	char	**tab_dir;
	char	*path;
	char	**tmp;

	(void)option;
	if (*curpath == '/')	
		curpath++;
	tab_dir = ft_strsplit(curpath, '/'); 
	if ((path = ft_construct_path(tab_dir)) == NULL)
		return (1);
	if (chdir(path) == 0)
	{
		tmp = ft_grep_env(env, "OLDPWD");
		free(*tmp);
		*tmp = ft_strjoin("OLDPWD=", ft_grep_envdata(env, "PWD"));
		tmp = ft_grep_env(env, "PWD");
		free(*tmp);
		*tmp = ft_strjoin("PWD=", path);
		free(path);
	}
	return (1);
}

char		*ft_read_cdpath(char *arg, char **env)
{
	char	**tab;
	char	*path;
	char	*data;

	data = ft_grep_envdata(env, "CDPATH");
	tab = ft_strsplit(data, ';');
	if (!tab)
		return (NULL);
	path = ft_strnew(256);
	while (*tab)
	{	
		ft_strcpy(path, *tab);
		ft_strcat(path, "/");
	   	ft_strcat(path, arg);
		ft_bzero(path, 256);
		tab++;
	}
	ft_strcat(path, "./");
	ft_strcat(path, arg);
	if (ft_check_dir(path) == 1)
		return (path);
	free(path);
	return (NULL);
}
		
int			ft_cd(char **arg, char **env)
{
	char	*path;

	if (!arg)
		return (1);
	arg++;
	if (ft_grep_envdata(env, "HOME") == NULL && *arg == NULL)
		return (ft_home_error());
	if (ft_grep_envdata(env, "HOME") != NULL && *arg == NULL)
		*arg = ft_grep_envdata(env, "HOME");
	if (*arg)
	{
		if (ft_strncmp(*arg, "/", 1) == 0)
			return (ft_process_cd(*arg, ft_builtin_option(arg), env));
		if (ft_strncmp(*arg, ".", 1) != 0 || ft_strncmp(*arg, "..", 2) != 0)
			if ((path = ft_read_cdpath(*arg, env)) != NULL)
				return (ft_process_cd(path, ft_builtin_option(arg), env));
		path = ft_strnew(256);	
		ft_strcpy(path, ft_grep_envdata(env, "PWD"));
		ft_strcat(path, "/");
		ft_process_cd(ft_strcat(path, *arg), ft_builtin_option(arg), env);
	}
	return (1);
}
