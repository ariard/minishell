/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:27:35 by ariard            #+#    #+#             */
/*   Updated: 2017/01/08 17:59:46 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_echo(char **arg, char **env)
{
	(void)env;
	if (!arg)
		return (1);
	arg++;
	if (*arg)
		ft_putarray(arg, 32, 10);
	else
		ft_putchar(10);
	return (1);
}

int			ft_check_next_component(char *str)
{
	int		i;

	i = 1;
	str++;
	while (*str != '/')
	{
		i++;
		str++;
	}
	if (ft_strcmp(str, "/..") == 0)
		return (i);
	return (0);
}

char		*ft_clean_curpath(char *curpath)
{
	char	*new;
	char	*tmp;
	int		ret;

	new = ft_strnew(256);
	tmp = new;
	while (*curpath)
	{
		if (*curpath == '/')
			if ((ret = ft_check_next_component(curpath)))
				curpath += ret;
		if (*curpath)
			if (ft_strncmp(curpath, "//", 2) == 0)
				curpath++;
		if (*curpath)
			if (*(curpath - 1))
				if (*(curpath - 1) != '.')
					if (ft_strncmp(curpath, "./", 2) == 0)
						curpath += 2;
		if (*curpath)
			*new++ = *curpath++;
	}
	*new = 0;
	return (tmp);
}
	
int			ft_process_cd(char *old, char *option, char **env)
{
	char	*curpath;
	char	*tmp;

	(void)option;
	(void)env;
	curpath	= ft_clean_curpath(old);
	tmp = curpath;
	ft_putstr(tmp);
	return (1);
}

int			ft_cd(char **arg, char **env)
{
	char	curpath[256];
	char	*option;

	ft_bzero(curpath, 256);
	if (!arg)
		return (1);
	arg++;
	option = ft_builtin_option(arg);
	if (ft_grep_env(env, "HOME") == NULL && *arg == NULL)
		return (ft_home_error());
	if (ft_grep_env(env, "HOME") != NULL && *arg == NULL)
		*arg = ft_grep_env(env, "HOME");
	if (*arg)
	{
		if (ft_strncmp(*arg, "/", 1) == 0)
			return (ft_process_cd(*arg, option, env));
		if (ft_strncmp(*arg, ".", 1) != 0 || ft_strncmp(*arg, "..", 2) != 0)
		{
//			if (ft_strcpy(curpath, ft_success) != NULL)
//				ft_process_cd(curpath, option, env);
//			else
//			{	
				ft_bzero(curpath, 256);
				ft_strcpy(curpath, ft_grep_env(env, "PWD"));
				ft_strcat(curpath, "/");
				ft_process_cd(ft_strcat(curpath, *arg), option, env);
//			}
		}
	}
	return (1);
}
