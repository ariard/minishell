/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:25:11 by ariard            #+#    #+#             */
/*   Updated: 2017/01/23 17:25:33 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_close_pipe(t_info *info)
{
	close(0);
	open("/dev/stdout", O_WRONLY);
	info->pipe = 0;
	return (0);
}

char	**ft_quoteis(t_btree *node)
{
	t_token		*token;
	char		**arg;	
	char		**tmp;

	if (!node)
		return (NULL);
	token = node->data;
	arg = ft_memalloc(sizeof(char *) * 3);
	tmp = arg;
	*arg++ = ft_strduptr(token->name, ft_isspace);
	token->name++;
	while (*(token->name - 1) && ft_isspace(*(token->name - 1)) != 1)
		token->name++;
	while (ft_isspace(*(token->name)) == 1)
		token->name++;
	*arg++ = ft_strdup(token->name);
	*arg = NULL;
	return (tmp);
}
