/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:07:37 by ariard            #+#    #+#             */
/*   Updated: 2016/12/11 16:43:33 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

static void		ft_reverse(char *s)
{
	int			c;
	int			i;
	int			j;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		j--;
	}
}

static size_t	ft_size_nbr(int n)
{
	size_t		len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	if (n == 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char		*s;
	int			i;
	int			sign;
	long long	nb;

	nb = n;
	if ((sign = nb) < 0)
		nb = -nb;
	s = (char *)malloc(sizeof(char) * ft_size_nbr(n) + 1);
	if (!(s))
		return (NULL);
	i = 0;
	if (nb == 0)
		s[i++] = '0';
	while (nb > 0)
	{
		s[i++] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	ft_reverse(s);
	return (s);
}
