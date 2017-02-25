/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:25:11 by ariard            #+#    #+#             */
/*   Updated: 2017/02/21 14:35:24 by ariard           ###   ########.fr       */
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
