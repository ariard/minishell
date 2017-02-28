/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:25:11 by ariard            #+#    #+#             */
/*   Updated: 2017/02/26 16:32:44 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_close_pipe(t_info *info)
{
	close(0);
	open("/dev/stdout", O_WRONLY);
	info->pipe = 0;
	return (0);
}

char		**ft_quoteis(t_btree *node)
{
	t_token		*token;
	char		**arg;
	char		**tmp;
	char		*cp;

	ft_putstr_fd("quote", 3);
	if (!node)
		return (NULL);
	token = node->data;
	cp = token->name;
	arg = ft_memalloc(sizeof(char *) * 3);
	tmp = arg;
	*arg++ = ft_strduptr(cp, ft_isspace);
	cp++;
	while (*(cp - 1) && ft_isspace(*(cp - 1)) != 1)
		cp++;
	while (ft_isspace(*(cp)) == 1)
		cp++;
	*arg++ = ft_strdup(cp);
	*arg = NULL;
	return (tmp);
}

int			ft_flush(t_btree *node)
{
	char	*file;
	int		fd;
	int		c;

	c = '\0';
	file = ft_node_nameis(node);
	if ((fd = open(file, O_CREAT | O_TRUNC, 0644)))
		return (-1);
	return (0);
}
