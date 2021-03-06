/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 22:09:47 by ariard            #+#    #+#             */
/*   Updated: 2017/01/06 15:48:32 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				ft_syntax_error(t_dlist *list_token)
{
	t_token		*token;

	if (list_token)
		if (list_token->data)
		{
			token = list_token->data;
			ft_putstr_fd("ariard : syntax error near unexpected token '", 2);
			ft_putstr_fd(token->name, 2);
			ft_putstr_fd("'\n", 2);
		}
	return (-1);
}

void		ft_semantic_error(char *s)
{
	ft_putstr_fd("ariard: ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd(": commmand not found\n", 2);
}

void		ft_permission_error(char *s, char **env)
{
	char	*log;

	while (*env && ft_strncmp(*env, "LOGNAME", 7) != 0)
		env++;
	log = *env;
	while (*log && *(log - 1) != '=')
		log++;
	ft_putstr_fd(s, 2);
	ft_putstr_fd(": you (", 2);
	ft_putstr_fd(log, 2);
	ft_putstr_fd(") are not allowed to use this program\n", 2);	
}
