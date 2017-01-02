/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 22:13:19 by ariard            #+#    #+#             */
/*   Updated: 2017/01/03 00:13:45 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		**ft_array_strdup(char **env)
{
	int			size;
	char		**tmp;
	char		**new;

	size = 0;
	tmp = env;
	while (*tmp++)
		size++;
	new = ft_memalloc(sizeof(char *) * (size + 1));
	tmp = new;
	while (*env)
		*new++ = ft_strdup(*env++);
	*new = 0;
	return (tmp);
}

t_cht			*ft_gen_symtab(char **env)
{
	char		**array;

	array =	ft_array_strdup(env);
	while (*array)
	{
		ft_putstr(*array++);
		ft_putchar(10);
	}
	return (NULL);
}
