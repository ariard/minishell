/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 18:32:40 by ariard            #+#    #+#             */
/*   Updated: 2017/01/09 23:48:32 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_env(char **arg, char **env)
{
	char	*option;

	if (!arg || !*arg || !env)
		return (1);
	option = ft_builtin_option(arg, "env");
	arg++;
	if (*arg)
	{	
		while (*arg)
		{
			env = ft_setenv(*arg, env);
			arg++;
		}
	}
	ft_read_env(env);
	return (1);
}

char		**ft_setenv(char *arg, char **env)
{
	char	*var;
	char	**del;
	char	*tmp;

	if (!arg || !env)
		return (NULL);
	if (arg)
	{
		tmp = ft_strnew(256);
		ft_strchrcpy(tmp, arg, '=');
		ft_str_substitute(tmp, '=', 0);
		del = ft_grep_env(env, tmp);
		free(tmp);
		if (!del)
			var = arg;
		else
			var = *del;
		env = ft_array_del(env, var);
		env = ft_array_add(env, arg);
	}
	return (env);
}

int			ft_unsetenv(char **arg, char **env)
{
	char	**del;

	if (!arg || !env)
		return (1);
	arg++;
	if (*arg)
	{
		del = ft_grep_env(env, *arg);
		if (del)
			if (*del)
				env = ft_array_del(env, *del);
	}
	return (1);
}
