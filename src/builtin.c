/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 16:35:47 by ariard            #+#    #+#             */
/*   Updated: 2017/02/26 16:36:33 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_isbuiltin(t_btree *node)
{
	char		*str;

	str = ft_node_nameis(node);
	if (ft_strncmp("echo", str, 4) == 0)
		return (1);
	if (ft_strncmp("cd", str, 2) == 0)
		return (1);
	if (ft_strncmp("setenv", str, 6) == 0)
		return (1);
	if (ft_strcmp("unsetenv", str) == 0)
		return (1);
	if (ft_strcmp("env", str) == 0)
		return (1);
	return (0);
}

int			ft_builtin(char *name, char **str, t_info *info)
{
	int		ret;

	ret = 0;
	if (ft_strncmp("echo", name, 4) == 0)
		ret = ft_echo(str, info);
	if (ft_strncmp("cd", name, 2) == 0)
		ret = ft_cd(str, info);
	if (ft_strncmp("setenv", name, 6) == 0)
	{
		ft_setenv(*(str + 1), info);
		ft_strdel(&name);
		return (1);
	}
	if (ft_strcmp("unsetenv", name) == 0)
		ret = ft_unsetenv(str, info);
	if (ft_strcmp("env", name) == 0)
		ret = ft_env(str, info);
	ft_strdel(&name);
	return (ret);
}

char		*ft_builtin_option(char **arg, char *builtin)
{
	char	*option;

	return (NULL);
	if (!arg || !*arg)
		return (NULL);
	while (*arg)
	{
		if (ft_strcmp(*arg, "-P") == 0 && ft_strcmp(builtin, "cd") == 0)
			option = "P";
		if (ft_strcmp(*arg, "-L") == 0 && ft_strcmp(builtin, "cd") == 0)
			option = "L";
		arg++;
	}
	return (option);
}

int			ft_check_dir(char *path)
{
	DIR		*ds;

	ds = opendir(path);
	if (!ds)
		return (ft_existence_error("cd", path));
	closedir(ds);
	return (1);
}
