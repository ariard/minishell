/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 14:54:04 by ariard            #+#    #+#             */
/*   Updated: 2016/12/31 15:26:01 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_detect_pattern(char *tab)
{
	char	*lexem;
	int		ret;

	lexem = ft_strnew(1024);
	while (*tab)
	{
		if (ret = ft_isoperand(tab))
			return (ft_strncpy(lexem, tab, ret));
		if (ret = ft_isoperator(tab))
			return (ft_strncpy(lexem, tab, ret));
		if (ret)
			tab += ret;
		else
			tab++;
	}
}

void		ft_lexer(char *tab)
{
	while (*tab)
	{
		ft_detect_pattern();
//		ft_match_pattern();
//		ft_gen_lexemes;
	}
}
