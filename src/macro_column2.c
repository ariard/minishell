/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_column2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 00:09:45 by ariard            #+#    #+#             */
/*   Updated: 2017/01/17 00:15:27 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_space(char *buf, int max, char *s)
{
	int		to_space;

	to_space = max - (int)ft_strlen(s);
	while (to_space--)
		ft_strcat(buf, " ");
}
