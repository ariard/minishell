/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 18:32:40 by ariard            #+#    #+#             */
/*   Updated: 2017/01/28 15:51:06 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_env(char **arg, t_info *info)
{
	char	*option;

	if (!arg || !*arg || !info->env)
		return (1);
	option = ft_builtin_option(arg, "env");
	arg++;
	if (*arg)
	{	
		while (*arg)
		{
			ft_setenv(*arg, info);
			arg++;				
		}
	}
	ft_read_env(info->env);
	return (1);
}

char		**ft_setenv(char *arg, t_info *info)
{
	char	*var;
	char	**del;
	char	*tmp;

	if (!arg || !info->env)
		return (NULL);
	if (arg)
	{
		tmp = ft_strnew(256);
		ft_strchrcpy(tmp, arg, '=');
		ft_str_substitute(tmp, '=', 0);
		del = ft_grep_env(info->env, tmp);
		free(tmp);
		if (!del)
			var = arg;
		else
			var = *del;
		info->env = ft_array_del(info->env, var);
		info->env = ft_array_add(info->env, arg);
	}
	return (info->env);
}

int			ft_unsetenv(char **arg, t_info *info)
{
	char	**del;

	if (!arg || !info->env)
		return (1);
	arg++;
	if (*arg)
	{
		del = ft_grep_env(info->env, *arg);
		if (del)
			if (*del)	
				info->env = ft_array_del(info->env, *del);
	}
	return (1);
}
