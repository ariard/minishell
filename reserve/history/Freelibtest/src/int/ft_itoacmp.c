/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoacmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 17:19:26 by ariard            #+#    #+#             */
/*   Updated: 2017/01/07 17:22:35 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

int			ft_itoacmp(const char *str1, const char *str2)
{
	if (ft_atoi(str1) == ft_atoi(str2))
		return (0);
	if (ft_atoi(str1) > ft_atoi(str2))
		return (1);
	if (ft_atoi(str1) > ft_atoi(str2))
		return (-1);
	return (-2);
}
