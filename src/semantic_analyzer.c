/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_executer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:37:58 by ariard            #+#    #+#             */
/*   Updated: 2017/01/28 22:05:39 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_btree			*ft_jump_nxt_operand(t_root *tree, t_btree *node)
{
	t_btree		*father;

	father = ft_get_father(tree->root, tree->root, node->key, &ft_itoacmp);
	node = ft_goto_nxt_operand(node, father);
	if (!node)
		return (NULL);
	father = ft_get_father(tree->root, tree->root, node->key, &ft_itoacmp);
	node = ft_goto_nxt_operand(node, father);
	return (node);
}

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
		t_root *tree, t_info *info)
{
	if (ft_node_islast(tree->size, node->key) == 1)
		return (ft_execute_regular(path, node, info));
	if (ft_ispipe(father) == 1)
	{
		info->pipe = 1;
		return (ft_execute_pipe(path, node, info));
	}
	if (ft_isregular(father) == 1)
		return (ft_execute_regular(path, node, info));
	if (ft_isheredoc(father) == 1)
		return (ft_execute_heredoc(path, node, father, info));
	if (ft_isredir_out(father) == 1)
		return (ft_redir_out(path, node, father, info));
	if (ft_isredir_in(father) == 1)
		return (ft_redir_in(path, node, father, info));
	if (ft_isappredir_out(father) == 1)
		return (ft_app_redir_out(path, node, father, info));
	return (0);
}

int				ft_execute_operand(t_btree *node, t_btree *father, t_info *info,
		t_root *tree)
{
	t_entry		*entry;
	char		*operand;

	if (!(operand = ft_node_nameis(node))) 
		return (-1);
	if (ft_strncmp(operand, "exit", 4) == 0)
	{
		ft_putstr("exit");
		exit(0);
	}
	else if (ft_strcmp(operand, "setenv") == 0 
		|| ft_strcmp(operand, "unsetenv") == 0 || ft_strcmp(operand, "echo") == 0
			|| ft_strcmp(operand, "env") == 0 || ft_strcmp(operand, "cd") == 0)
		return (ft_execute_cmd(operand, node, father, tree, info));
	if (ft_full_path(operand))
		return (ft_execute_cmd(operand, node, father, tree, info));
	if (operand[0] == '/')
		return (ft_existence_error("ariard", operand));
	entry = ft_add_bin(operand, info);
	if (!entry) 
		return (ft_semantic_error(operand));
	else if (entry)
	{
		if (entry->perm == -1)
			return (ft_permission_error(operand, info->env));
		else if (entry->perm == 0)
			return (ft_execute_cmd(entry->path, node, father, tree, info)); 
	}
	return (0);	
}

void			ft_execute_ast(t_root *tree, t_info *info) 
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
		if (ft_isredir_out(father) || ft_isredir_in(father) 
			|| ft_isappredir_out(father))
			ret = ft_execute_all_dir(tmp, father, info, tree);
		else
			ret = ft_execute_operand(tmp, father, info, tree);
		if ((ft_islistand(father) == 1 && ret == -1) || ft_isheredoc(father))
			tmp = ft_jump_nxt_operand(tree, tmp);
		else if (ft_islistor(father) == 1 && ret == 1)
			tmp = ft_jump_nxt_operand(tree, tmp);
		else if (ft_ispipe(father) == 1 && ret == -1) 
			tmp = ft_jump_nxt_operand(tree, tmp);
		else
			tmp = ft_goto_nxt_operand(tmp, father);
		info->prev_father = father;
	}
}
