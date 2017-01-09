/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_operand2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 00:02:58 by ariard            #+#    #+#             */
/*   Updated: 2017/01/09 16:49:42 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_builtin(t_btree *node, t_btree *father, char **env)
{	
	char		**str;

	str = ft_node_argis(node);
	(void)father;
	(void)env;
	if (ft_strncmp("echo", *str, 4) == 0)
		return (ft_echo(str, env));
	if (ft_strncmp("cd", *str, 4) == 0)
		return (ft_cd(str, env));
	if (ft_strcmp("setenv", *str) == 0)
		return (1);
	if (ft_strcmp("unsetenv", *str) == 0)
		return (1);
	if (ft_strcmp("env", *str) == 0)
		return (1);
	if (ft_strcmp("exit", *str) == 0)
		return (1);
	return (0);
}

char		*ft_builtin_option(char **arg)
{
	char	*option;

	if (!arg || !*arg)
		return (NULL);
	while (*arg)
	{
		if (ft_strcmp(*arg, "-P"))
			option = "P";
		if (ft_strcmp(*arg, "-L"))
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
