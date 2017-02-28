/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 18:32:40 by ariard            #+#    #+#             */
/*   Updated: 2017/02/27 20:36:29 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_execute_env(char *path, t_info *info)
{
	pid_t	status;
	char	*arg[2];

	arg[0] = path;
	arg[1] = NULL;
	status = fork();
	if (status == 0)
	{
		signal(SIGINT, ft_sigint_handler_child);
		execve(path, arg, info->env);
	}
	if (status > 0)
		wait(0);
}

int			ft_env(char **arg, t_info *info)
{
	char	*var;
	t_entry	*entry;

	entry = NULL;
	if (!arg || !*arg || !info->env)
		return (1);
	arg++;
	while (*arg)
	{
		if ((var = strrchr(*arg, '=')) && ft_strlen(*arg) > 1)
			ft_setenv(*arg, info);
		else if ((entry = ft_add_bin(*arg, info)))
		{
			if (entry->perm == -1)
				return (ft_permission_error(*arg, info->env));
			if (entry->perm == 0)
				ft_execute_env(entry->path, info);
		}
		else if (!var && !entry)
			return (ft_existence_error("env", *arg));
		arg++;
	}
	if (!entry)
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
		{
			var = *del;
			info->env = ft_array_del(info->env, var);
		}
		info->env = ft_array_add(info->env, arg);
	}
	return (info->env);
}

int			ft_unsetenv(char **arg, t_info *info)
{
	char	**del;

	del = NULL;
	if (!arg || !info->env)
		return (1);
	arg++;
	if (*arg)
	{
		ft_putstr_fd("still alive", 3);
		del = ft_grep_env(info->env, *arg);
		if (del)
			if (*del)
				info->env = ft_array_del(info->env, *del);
	}
	return (1);
}
