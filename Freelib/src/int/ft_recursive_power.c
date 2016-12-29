/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 17:29:32 by ariard            #+#    #+#             */
/*   Updated: 2016/12/11 17:35:59 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

int			ft_recursive_power(int nb, int power)
{
	if (power > 1)
		nb = (nb * ft_recursive_power(nb, power - 1));
	if (power == 0)
		nb = 1;
	if (power < 0)
		nb = 1;
	return (nb);
}
