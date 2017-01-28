/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 14:21:51 by ariard            #+#    #+#             */
/*   Updated: 2017/01/28 15:48:51 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_grep_envdata(char **env, char *value)
{
	char	var[100];
	char	*data;

	if (!env || !*env || !value)
		return (NULL);
	ft_bzero(var, 100);
	ft_strcpy(var, value);
	ft_strcat(var, "=");
	while (*env)
	{
		if (ft_strncmp(*env, var, ft_strlen(var)) == 0)
		{
			data = *env;
			while (*data && *data != '=')
				data++;
			data++;
			return (data);
		}
		env++;
	}
	return (NULL);
}

char		**ft_grep_env(char **env, char *value)
{
	char	var[100];

	if (!env || !*env || !value)
		return (NULL);
	ft_bzero(var, 100);
	ft_strcpy(var, value);
	ft_strcat(var, "=");
	while (*env)
	{
		if (ft_strncmp(*env, var, ft_strlen(var)) == 0)
			return (env);
		env++;
	}
	return (NULL);
}
