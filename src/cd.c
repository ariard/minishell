/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:27:35 by ariard            #+#    #+#             */
/*   Updated: 2017/02/27 17:41:14 by ariard           ###   ########.fr       */
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
		if (ft_strcmp(".", *new_tab_dir) == 0)
			break ;
		if (*(new_tab_dir + 1) && ft_strcmp("..", *(new_tab_dir + 1)) == 0)
			break ;
		ft_strcat(path, *new_tab_dir);
		if (*(new_tab_dir + 1) && ft_strcmp(*(new_tab_dir + 1), ".") != 0)
			ft_strcat(path, "/");
		if (ft_check_dir(path) == -1)
		{
			free(path);
			return (NULL);
		}
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
	path = NULL;
	if (*curpath == '/')
		curpath++;
	new_tab_dir = ft_strsplit(curpath, '/');
	path = ft_construct_path(new_tab_dir);
	ft_array_clean(new_tab_dir);
	if (!path)
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
	char	**temp;
	char	*path;
	char	*data;

	data = ft_grep_envdata(env, "CDPATH");
	if (!(new_tab = ft_strsplit(data, ';')))
		return (NULL);
	temp = new_tab;
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
	ft_array_clean(temp);
	if (ft_check_dir(path) == 1)
		return (path);
	free(path);
	return (NULL);
}

static int	ft_cd2(char **arg, t_info *info)
{
	char	*home;

	if (ft_grep_envdata(info->env, "HOME") == NULL && *arg == NULL)
		return (ft_home_error());
	if (ft_grep_envdata(info->env, "HOME") != NULL && *arg == NULL)
	{
		home = ft_strdup(ft_grep_envdata(info->env, "HOME"));
		ft_process_cd(home, "HOME", info);
		ft_strdel(&home);
		return (1);
	}
	if (ft_strcmp(*arg, "-") == 0)
	{
		return (ft_process_cd(ft_grep_envdata(info->env, "OLDPWD"),
			ft_builtin_option(arg, "cd"), info));
	}
	return (0);
}

int			ft_cd(char **arg, t_info *info)
{
	char	*path;

	if (!arg)
		return (1);
	if (ft_cd2(++arg, info))
		return (1);
	if (*arg)
	{
		if (ft_strncmp(*arg, "/", 1) == 0)
			return (ft_process_cd(*arg, ft_builtin_option(arg, "cd"), info));
		if (ft_strncmp(*arg, ".", 1) != 0 || ft_strncmp(*arg, "..", 2) != 0)
			if ((path = ft_read_cdpath(*arg, info->env)) != NULL)
			{
				ft_process_cd(path, ft_builtin_option(arg, "cd"), info);
				free(&path);
				return (1);
			}
		path = ft_strnew(256);
		ft_strcpy(path, ft_grep_envdata(info->env, "PWD"));
		ft_strcat(path, "/");
		ft_process_cd(ft_strcat(path, *arg), ft_builtin_option(arg, "cd"),
			info);
		free(path);
	}
	return (1);
}
