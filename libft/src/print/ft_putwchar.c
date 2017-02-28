/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 17:37:31 by ariard            #+#    #+#             */
/*   Updated: 2017/01/08 17:58:45 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

static char			*ft_fill(char *tab, char s[], char to_print[], int len3)
{
	int				len;
	int				len2;

	len = ft_strlen(tab) - 1;
	len2 = ft_strlen(s) - 1;
	while (len >= 0)
	{
		if (tab[len] == 'x' && len2 >= 0)
			to_print[len3] = s[len2--];
		else
			to_print[len3] = tab[len];
		len--;
		len2--;
	}
	len3++;
	while (to_print[len3])
	{
		if (to_print[len3] == 'x')
			to_print[len3] = '0';
		len3++;
	}
	return (to_print);
}

static int			ft_print_wchar(char *tab, wchar_t w, int len2)
{
	char			to_print[128];
	char			s[128];
	char			new[9];
	int				len;
	int				n;

	ft_bzero(to_print, 128);
	ft_bzero(s, 128);
	ft_itoa_base((unsigned long long int)w, 2);
	ft_fill(tab, s, to_print, len2);
	len2 = 0;
	len = ft_strlen(to_print);
	n = 0;
	while (len2 < len)
	{
		ft_bzero(new, 9);
		ft_strchrcpy(new, &to_print[len], ' ');
		ft_putchar(ft_atoi_base(new, 2));
		n++;
	}
	return (n);
}

int					ft_putwchar(wchar_t w)
{
	char			*tab;
	int				len;
	char			n;

	n = 0;
	if (w < 2048)
	{
		tab = "110xxxxx 10xxxxxx";
		len = 16;
		n = ft_print_wchar(tab, w, len);
	}
	if (w < 65536)
	{
		tab = "1110xxxx 10xxxxxx 10xxxxxx";
		len = 25;
		n = ft_print_wchar(tab, w, len);
	}
	else
	{
		tab = "11110xxx 10xxxxxx 10xxxxxx 10xxxxxx";
		len = 34;
		n = ft_print_wchar(tab, w, len);
	}
	return (n);
}
