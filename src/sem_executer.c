/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_executer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:37:58 by ariard            #+#    #+#             */
/*   Updated: 2017/01/07 16:26:20 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*ft_read_cmd(t_btree *node)
{
	t_token		*token;

	if (node)
	{
		token = node->data;
		if (ft_strcmp(token->id, "operator") == 0)
		{
			node = node->left;
			if (node)
			{
				token = node->data;
				return (token->name);
			}
		}
		else
			return (token->name);
	}
	return (NULL);
}

t_btree			*ft_goto_nxt_cmd(t_btree *node, t_btree *father)
{
	if (!father)
		return (NULL);
	if (father->right)
		if (ft_strcmp((char *)(father->right)->key, (char *)node->key) == 0)
			return (NULL);
	if (father->left)
	{
		if (ft_strcmp((char *)(father->left)->key, (char *)node->key) == 0)
		{
			if (father->right)
			{
				if (ft_nodeis(father->right) == 0)
					return ((father->right)->left);
				else
					return (father->right);
			}
			else
				return (NULL);

		}
	}
	return (NULL);
}

static int		ft_itoacmp(const char *str1, const char *str2)
{
	if (ft_atoi(str1) == ft_atoi(str2))
		return (0);
	return (1);
}

void			ft_execute_ast(t_root *tree, char **env, t_cht *sym_tab)
{
	t_btree		*tmp;
	t_btree		*father;
	t_entry		*entry;
	char		*cmd;

	tmp = tree->root;
	if (ft_nodeis(tree->root) == 0)
		tmp = (tree->root)->left;
	while (tmp)
	{
		cmd = ft_read_cmd(tmp);
		entry = ft_cht_lookup(sym_tab, ft_strduptr(cmd, &ft_isspace), &ft_strcmp);
		if (!entry)
			ft_semantic_error(ft_strduptr(cmd, &ft_isspace));
		if (entry)
			if (entry->x == -1)
				ft_permission_error(cmd, env);
		father = ft_get_father(tree->root, tree->root, tmp->key, &ft_itoacmp);
		if (entry)
			if (entry->x == 0)
				ft_execute_cmd(entry->path, tmp, father, env);
		tmp = ft_goto_nxt_cmd(tmp, father);
	}
}
