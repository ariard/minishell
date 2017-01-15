/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_clean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 19:06:34 by ariard            #+#    #+#             */
/*   Updated: 2017/01/09 20:45:34 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void		ft_array_clean(char **array)
{
	if (!array)
		return ;
	while (*array)
	{
		ft_strdel(array);
		array++;
	}	
	array = NULL;
}
