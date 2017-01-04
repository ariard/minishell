/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyze.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 21:39:33 by ariard            #+#    #+#             */
/*   Updated: 2017/01/04 22:48:52 by ariard           ###   ########.fr       */
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

void			ft_syntax_analyze(t_dlist **list_token)
{
	t_dlist		*tmp;
	t_expr		*expr;
	int			ret;

	if (!*list_token)
		return ;
	tmp = *list_token;
	expr = ft_find_expr(tmp);
	ret = ft_eval_expr(expr, tmp);
	if (ret == -1)
		return ;
	if (ret == 1)
		ft_putstr("cmd\n");	
	if (ret == 2)
	{
		ft_putstr("cmd ope ou cmd ope cmd\n");
	}
}
