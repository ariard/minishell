/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 19:42:44 by ariard            #+#    #+#             */
/*   Updated: 2016/12/29 20:04:45 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "dlist.h"

typedef t_dlist		t_stack;

void				ft_stack_pop(t_stack **stack, void *(*destroy)(void *)); 

void				ft_stack_push(t_stack **stack, void *data,
	t_stack *(*create)(void *));

void				ft_stack_peek(t_stack **stack);

#endif
