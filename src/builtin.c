/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_operand2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 00:02:58 by ariard            #+#    #+#             */
/*   Updated: 2017/01/08 00:15:46 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_builtin(char *str, t_btree *node, t_btree *father, char **env)
{
	if (ft_strcmp("echo", str) == 0)
		return (1);
	if (ft_strcmp("cd", str) == 0)
		return (1);
	if (ft_strcmp("setenv", str) == 0)
		return (1);
	if (ft_strcmp("unsetenv", str) == 0)
		return (1);
	if (ft_strcmp("env", str) == 0)
		return (1);
	if (ft_strcmp("exit", str) == 0)
		return (1);
	return (0);
}	
