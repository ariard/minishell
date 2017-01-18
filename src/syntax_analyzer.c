/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyze.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 21:39:33 by ariard            #+#    #+#             */
/*   Updated: 2017/01/18 18:05:45 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_init_expr(t_expr *expr)
{
	expr->id1 = 0;
	expr->id2 = 0;
	expr->id3 = 0;
}

static t_expr	*ft_find_expr(t_dlist *list_token)
{
	t_token		*token;
	t_expr		*expr;

	expr = ft_memalloc(sizeof(t_expr));
	ft_init_expr(expr);
	if (list_token)
		if (list_token->data)
		{	
			token = list_token->data;
			expr->id1 = token->id;
			list_token = list_token->next;
			if (list_token)
				if (list_token->data)
				{
					token = list_token->data;
					expr->id2 = token->id;
					list_token = list_token->next;
					if (list_token)		
						if (list_token->data)
						{
							token = list_token->data;
							expr->id3 = token->id;
						}
				}
		}
	return (expr);
}

static int		ft_eval_expr(t_expr *expr, t_dlist *list_token)
{
	if (expr->id1)
		if (ft_strcmp(expr->id1, "operand") == 0 && !expr->id2)
			return (1);
	if (expr->id1 && expr->id2)
		if (ft_strcmp(expr->id1, "operand") == 0 
				&& ft_strcmp(expr->id2, "operator") == 0 && !expr->id3)
			return (2);
	if (expr->id1 && expr->id2 && expr->id3)
		if (ft_strcmp(expr->id1, "operand") == 0 
				&& ft_strcmp(expr->id2, "operator") == 0
				&& ft_strcmp(expr->id3, "operand") == 0)
			return (2);
	if (expr->id1)
		if (ft_strcmp(expr->id1, "operator") == 0)
			return (ft_syntax_error(list_token));
	if (expr->id1 && expr->id2 && expr->id3)
		if (ft_strcmp(expr->id1, "operand") == 0 
				&& ft_strcmp(expr->id2, "operator") == 0
				&& ft_strcmp(expr->id3, "operator") == 0)
			return (ft_syntax_error((list_token->next)->next));
	return (0);
}

t_root			*ft_syntax_analyze(t_dlist **list_token)
{
	t_dlist		*tmp;
	t_expr		*expr;
	t_root		*tree;
	t_btree		*father;
	int			ret;

	tree = ft_memalloc(sizeof(t_root));
	ft_btree_init(tree, &ft_strcmp);
	father = NULL;
	if (!*list_token)
		return (NULL);
	tmp = *list_token;
	while (tmp)
	{
		expr = ft_find_expr(tmp);
		ret = ft_eval_expr(expr, tmp);
		if (ret == -1)
			return (NULL);
		if (ret == 2)
			father = ft_ast_insert_sequence(tree, father, tmp, tmp->next);
		if (ret == 1)
			father = ft_ast_insert_cmd(tree, father, tmp);	
		tmp = ft_list_next(tmp, ret);
	}
	return (tree);
}
