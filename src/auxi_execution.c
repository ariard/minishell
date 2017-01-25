/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:25:11 by ariard            #+#    #+#             */
/*   Updated: 2017/01/25 18:52:27 by ariard           ###   ########.fr       */
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

int			ft_multidir(t_btree *node, t_btree *father,
		t_info *info, t_root *tree)
{
	t_btree		*tmp;
	t_btree		*father_next;

	tmp = NULL;
	father_next = NULL;
	if (info->ismultidir == -2)	
		return (0);
	if (ft_isredir_out(father) == 1 || ft_isappredir_out(father) == 1
		|| ft_isredir_in(father) == 1)
	{
		tmp = ft_goto_nxt_operand(node, father);
		if (tmp)
			father_next = ft_get_father(tree->root, tree->root,
				tmp->key, &ft_itoacmp);
		if (father_next && ft_strcmp(father->key, father_next->key) != 0)
			if (ft_isredir_out(father_next) == 1 
				|| ft_isappredir_out(father_next) == 1
				|| ft_isredir_in(father_next) == 1)
			{
				if (info->ismultidir == 0)
				{	
					info->heritance = node;
					info->heritancefather = father;
				}
				info->ismultidir = 1;
				return (1);
			}
	}
	if (info->ismultidir == 1)
		info->ismultidir = 2;
	return (0);
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
