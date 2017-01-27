/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_operand2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 00:02:58 by ariard            #+#    #+#             */
/*   Updated: 2017/01/27 16:13:50 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_isbuiltin(t_btree *node)
{	
	char		**str;


	str = ft_node_argis(node);
	if (ft_strncmp("echo", *str, 4) == 0)
		return (1);
	if (ft_strncmp("cd", *str, 2) == 0)
		return (1);
	if (ft_strncmp("setenv", *str, 6) == 0)
		return (1);
	if (ft_strcmp("unsetenv", *str) == 0)
		return (1);
	if (ft_strcmp("env", *str) == 0)
		return (1);
	return (0);
}

int			ft_builtin(t_btree *node, char **env)
{	
	char		**str;
	char		*arg;

	str = ft_node_argis(node);
	arg = *(str + 1);
	if (ft_strncmp("echo", *str, 4) == 0)
		return (ft_echo(str, env));
	if (ft_strncmp("cd", *str, 2) == 0)
		return (ft_cd(str, env));
	if (ft_strncmp("setenv", *str, 6) == 0)
	{
		ft_setenv(arg, env);
		return (1);
	}
	if (ft_strcmp("unsetenv", *str) == 0)
		return (ft_unsetenv(str, env));
	if (ft_strcmp("env", *str) == 0)
		return (ft_env(str, env));
	return (0);
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
		if (ft_strcmp(*arg, "-i") == 0 && ft_strcmp(builtin, "env") == 0)
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
