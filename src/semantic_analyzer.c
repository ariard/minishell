/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_executer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:37:58 by ariard            #+#    #+#             */
/*   Updated: 2017/01/09 13:19:03 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_btree			*ft_goto_nxt_operand(t_btree *node, t_btree *father)
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
				if (ft_node_typeis(father->right) == 0)
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

int				ft_execute_cmd(char	*path, t_btree *node, t_btree *father,
		char **env, t_root *tree)
{
	static int	isinpipe;

	if (!isinpipe)
		isinpipe = 0;
	if (ft_node_islast(tree->size, node->key) == 1)
		return (ft_execute_regular(path, node, env, isinpipe));
	if (ft_ispipe(father) == 1)
	{
		isinpipe = 1;
		return (ft_execute_pipe(path, node, env));
	}
	if (ft_isregular(father) == 1)
		return (ft_execute_regular(path, node, env, isinpipe));
	if (ft_isredir_out(father) == 1)
		return (ft_redir_out(path, node, father, env));
	if (ft_isredir_in(father) == 1)
		return (ft_redir_in(path, node, father, env));
	if (ft_isappredir_out(father) == 1)
		return (ft_app_redir_out(path, node, father, env));
	return (0);
}

int				ft_execute_operand(t_btree *node, t_btree *father, char **env,
		t_cht *sym_tab, t_root *tree)
{
	t_entry		*entry;
	char		*operand;

	if (!(operand = ft_node_nameis(node))) 
		return (-1);
	entry = ft_cht_lookup(sym_tab, operand, &ft_strcmp);
	if (!entry)
		return (ft_semantic_error(operand));
	else
	{
		if (ft_builtin(node, father, env) == 1)
			return (1);
		if (entry->perm == -1)
			return (ft_permission_error(operand, env));
		else if (entry->perm == 0)
			return (ft_execute_cmd(entry->path, node, father, env, tree));
	}
	return (0);	
}

void			ft_execute_ast(t_root *tree, char **env, t_cht *sym_tab)
{
	t_btree 	*tmp;
	t_btree		*father;
	int			ret;

	tmp = tree->root;
	if (ft_node_typeis(tree->root) == 0)
		tmp = (tree->root)->left;
	while (tmp)
	{
		father = ft_get_father(tree->root, tree->root, tmp->key, &ft_itoacmp);
		ret = ft_execute_operand(tmp, father, env, sym_tab, tree);
		if (ft_isredir_out(father) == 1 || ft_isredir_in(father) == 1
				|| ft_isappredir_out(father) == 1)
			tmp = ft_goto_nxt_operand(tmp, father);
//		if (ft_islist(father) == 1 && ret = -1)
//			tmp = ft_jump_nxt_operand;
		tmp = ft_goto_nxt_operand(tmp, father);
	}
}
